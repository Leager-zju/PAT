#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define inf 10e7

struct node{
    int data;
    int tag;            // 1为黑 0为红
    node *left=NULL,*right=NULL;
    node(int x){
        data=abs(x);
        tag=x>0?1:0;
    }
};
void insert(node *&root,int x){
    if(root==NULL){
        root=new node(x);
        return;
    }
    if(abs(x)<=abs(root->data)) insert(root->left,x);
    else insert(root->right,x);
}
int getNum(node *root){
    if(root==NULL) return 1;
    int l=getNum(root->left);
    int r=getNum(root->right);
    return max(l,r)+root->tag;
}
bool isRBT(node *root){
    if(root==NULL) return true;
    if(root->tag==0){
        if(root->left!=NULL && root->left->tag==0) return false;
        if(root->right!=NULL && root->right->tag==0) return false;
    }
    int l=getNum(root->left);
    int r=getNum(root->right);
    if(l!=r) return false;
    else return ( isRBT(root->left) && isRBT(root->right) );
}
int main(){
    int n,k,x;
    cin>>n;
    while(n--){
        node *root=NULL;
        cin>>k;
        while(k--){
            cin>>x;
            insert(root,x);
        }
        if(root->tag==0 || !isRBT(root)) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}
