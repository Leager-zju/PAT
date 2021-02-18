#include<string>
#include<iostream>
using namespace std;

bool ischild[25]={false};
string ans;
int root;
struct node{
    string data;
    int left,right;
}tree[25];

void inorder(int v){
    if(v!=1){
        if(v!=root && (tree[v].left!=-1 || tree[v].right!=-1)) cout<<"(";
        inorder(tree[v].left);
        cout<<tree[v].data;
        inorder(tree[v].right);
        if(v!=root && (tree[v].left!=-1 || tree[v].right!=-1)) cout<<")";
    }
}

int main(){
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>tree[i].data>>tree[i].left>>tree[i].right;
        if(tree[i].left!=-1) ischild[tree[i].left]=true;
        if(tree[i].right!=-1) ischild[tree[i].right]=true;
    }
    for(i=1;i<=n;i++){
        if(!ischild[i]) break;
    }
    root=i;
    inorder(root);
}
