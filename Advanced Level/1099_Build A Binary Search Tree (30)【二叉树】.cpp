#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct node{
    int data,left,right;
}tree[105];

int list[105],now=0;
queue<node> levelorder;

void insert(int root){
    if(tree[root].left!=-1) insert(tree[root].left);
    tree[root].data=list[now++];
    if(tree[root].right!=-1) insert(tree[root].right);
}

int main(){
    int n,i,first=1;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>tree[i].left>>tree[i].right;
    }
    for(i=0;i<n;i++){
        cin>>list[i];
    }
    sort(list,list+n);
    insert(0);
    
    node top;
    levelorder.push(tree[0]);
    while(!levelorder.empty()){
        top=levelorder.front();
        levelorder.pop();
        if(first) first=0;
        else printf(" ");
        printf("%d",top.data);
        if(top.left!=-1) levelorder.push(tree[top.left]);
        if(top.right!=-1) levelorder.push(tree[top.right]);
    }
}
