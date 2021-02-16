#include<algorithm>
#include<queue>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;

vector<int> v;
struct node{
    int data;
    node *left=NULL,*right=NULL;
};

node* makeCBT(int left,int right){
    if(left>right) return NULL;
    int floor=(int)(log(right-left+1)/log(2));
    int mid;
    int bottom=3*pow(2,floor-1)-1;
    
    if(right-left+1>=bottom) mid=left-1+pow(2,floor);
    else mid=pow(2,floor)-bottom+right;
    
    node *root=new node;
    root->data=v[mid];
    root->left=makeCBT(left,mid-1);
    root->right=makeCBT(mid+1,right);
    return root;
}
void levelorder(node *root){
    int first=1;
    queue<node*> Q;
    Q.push(root);
    while(!Q.empty()){
        node *top=Q.front();
        Q.pop();
        if(first){
            printf("%d",top->data);
            first=0;
        }
        else printf(" %d",top->data);
        if(top->left) Q.push(top->left);
        if(top->right) Q.push(top->right);
    }
}

int main(){
    int n,i;
    scanf("%d",&n);
    v.resize(n+1);
    for(i=1;i<=n;i++){
        scanf("%d",&v[i]);
    }
    sort(v.begin()+1,v.end());
    node *root=makeCBT(1,n);
    levelorder(root);
}
