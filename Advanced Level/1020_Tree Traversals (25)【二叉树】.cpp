#include<vector>
#include<queue>
#include<cstdio>
using namespace std;

vector<int> postorder,inorder,levelorder;
int n;

struct node{
    int data;
    node* left,right;
    node(int x){
        data=x;
    }
};

node* maketree(int l1,int r1,int l2,int r2){
    if(l1>r1) return NULL;
    int pos;
    for(int i=l2;i<=r2;i++){
        if(inorder[i]==postorder[r1]) break;
    }
    pos=i;
    node* temp=new node(postorder[r1]);
    temp->left=maketree(l1,l1-l2+pos-1,l2,pos-1);
    temp->right=maketree(l1-l2+pos,r1-1,pos+1,r2);
    return temp;
}
void LevelOrderTheTree(node* root){
    queue<node*> Q;
    int num=0;
    Q.push(root);
    while(!Q.empty()){
        node* temp=Q.front();
        Q.pop();
        printf("%d",temp->data);
        num++;
        if(num<n) printf(" ");
        if(temp->left) Q.push(temp->left);
        if(temp->right) Q.push(temp->right);
    }
}

int main(){
    int temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        postorder.push_back(temp);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        inorder.push_back(temp);
    }
    node* root=maketree(0,n-1,0,n-1);
    LevelOrderTheTree(root);
    return 0;
}
