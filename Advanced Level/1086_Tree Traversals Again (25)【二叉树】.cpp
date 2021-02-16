#include<string>
#include<stack>
#include<vector>
#include<iostream>
using namespace std;

vector<int> preorder,inorder;
int first=1;

struct node{
    int data;
    node *left,*right;
};

node* maketree(int prel,int prer,int inl,int inr){
    if(prel>prer) return NULL;
    node* temp=new node;
    temp->data=preorder[prel];
    int i;
    for(i=inl;i<=inr;i++){
        if(inorder[i]==preorder[prel]){
            break;
        }
    }
    int lsize=i-inl;  // 左子树结点数
    temp->left=maketree(prel+1,prel+lsize,inl,i-1);
    temp->right=maketree(prel+lsize+1,prer,i+1,inr);
    return temp;
}

void postorder(node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        if(first) first=0;
        else printf(" ");
        printf("%d",root->data);
    }
}

int main(){
    int n,i,num;
    stack<int> tree;
    string op;
    
    cin>>n;
    for(i=0;i<2*n;i++){
        cin>>op;
        if(op=="Push"){
            cin>>num;
            preorder.push_back(num);
            tree.push(num);
        }
        else if(op=="Pop"){
            inorder.push_back(tree.top());
            tree.pop();
        }
    }
    node *root=maketree(0,n-1,0,n-1);
    postorder(root);
}
