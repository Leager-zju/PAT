#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct node{
    int data,height;
    node *left=NULL,*right=NULL;
    node(int x): data(x) {}
};

int getheight(node *&root){
    if(root==NULL) return 0;
    else return root->height;
}

int getbalancefactor(node *&root){
    return getheight(root->left)-getheight(root->right);
}

void updateheight(node *&root){
    root->height=max(getheight(root->left),getheight(root->right))+1;
}

void L(node *&root){
    node *temp=root->right;
    root->right=temp->left;
    temp->left=root;
    updateheight(root);
    updateheight(temp);
    root=temp;
}

void R(node *&root){
    node *temp=root->left;
    root->left=temp->right;
    temp->right=root;
    updateheight(root);
    updateheight(temp);
    root=temp;
}

void insert(node *&root,int num){
    if(root==NULL){
        root=new node(num);
        root->height=1;
        return;
    }
    if(num<root->data){
        insert(root->left,num);
        updateheight(root);
        if(getbalancefactor(root)==2){
            if(getbalancefactor(root->left)==1){
                R(root);
            }
            else if(getbalancefactor(root->left)==-1){
                L(root->left);
                R(root);
            }
        }
    }
    else{
        insert(root->right,num);
        updateheight(root);
        if(getbalancefactor(root)==-2){
            if(getbalancefactor(root->right)==-1){
                L(root);
            }
            else if(getbalancefactor(root->right)==1){
                R(root->right);
                L(root);
            }
        }
    }
}

int main(){
    int n,i,number,count=0,flag=0;
    node *root=NULL;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>number;
        insert(root,number);
    }
    
    queue<node*> Q;
    Q.push(root);
    while(!Q.empty()){
        root=Q.front();
        Q.pop();
        if(root->left) Q.push(root->left);
        if(root->right) Q.push(root->right);
        
        count++;
        if(count<=(n-1)/2 && (!root->left || !root->right)) flag=1;
        if(count==n/2 && n%2==0 && (!root->left || root->right)) flag=1;

        if(count!=1) cout<<" ";
        cout<<root->data;
    }
    if(flag) cout<<endl<<"NO";
    else cout<<endl<<"YES";
}
