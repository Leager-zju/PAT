#include<iostream>
using namespace std;

int in[50010],pre[50010];
struct node{
    int data;
    node *left=NULL,*right=NULL;
    node(int x){
        data=x;
    }
};
node *maketree(int l1,int r1,int l2,int r2){
    if(l1>r1) return NULL;
    int i,numofleft;
    for(i=l2;i<=r2;i++){
        if(in[i]==pre[l1]) break;
    }
    numofleft=i-l2;
    node *root=new node(pre[l1]);
    root->left=maketree(l1+1,l1+numofleft,l2,i-1);
    root->right=maketree(l1+numofleft+1,r1,i+1,r2);
    return root;
}

int main(){
    int n,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>pre[i];
    }
    for(i=0;i<n;i++){
        cin>>in[i];
    }
    node *root=maketree(0,n-1,0,n-1);
    while(root->left || root->right){
        if(root->left) root=root->left;
        else root=root->right;
    }
    cout<<root->data;
}
