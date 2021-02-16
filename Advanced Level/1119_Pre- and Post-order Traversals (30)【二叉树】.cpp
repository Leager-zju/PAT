#include<cstdio>

struct node{
    int data;
    node *left,*right;
    node(int x){
        data=x;
    }
};

int pre[32],post[32];
int first=1;
int flag=0,n;

void inorder(node *root){
    if(root){
        inorder(root->left);
        if(first) first=0;
        else printf(" ");
        printf("%d",root->data);
        inorder(root->right);
    }
}

void maketree(node *&root,int l1,int r1,int l2,int r2){
    if(l1>r1){
        root=NULL;
        return;
    }
    if(l1<n-1 && r2>0 && pre[l1+1]==post[r2-1]) flag=1;
    int i,numofleft=0;
    root=new node(pre[l1]);
    for(i=l2;i<=r2;i++){
        if(post[i]==pre[l1+1]) break;
    }
    if(i<=r2) numofleft=i-l2+1;
    maketree(root->left,l1+1,l1+numofleft,l2,i);
    maketree(root->right,l1+numofleft+1,r1,i+1,r2-1);
}

int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&pre[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d",&post[i]);
    }
    node *root;
    maketree(root,0,n-1,0,n-1);
    if(flag) printf("No\n");
    else printf("Yes\n");
    inorder(root);
    printf("\n");
}
