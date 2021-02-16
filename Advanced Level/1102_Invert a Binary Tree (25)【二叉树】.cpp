#include<iostream>
#include<queue>
using namespace std;

struct node{
    int data,left,right;
}tree[11];

int root,flag=1;

void levelorder(){
    queue<node> Q;
    Q.push(tree[root]);
    node temp;
    while(!Q.empty()){
        temp=Q.front();
        Q.pop();
        if(flag) flag=0;
        else cout<<" ";
        cout<<temp.data;
        if(temp.right!=-1) Q.push(tree[temp.right]);
        if(temp.left!=-1) Q.push(tree[temp.left]);
    }
    cout<<endl;
}
void inorder(int r){
    if(r!=-1){
        inorder(tree[r].right);
        if(flag) flag=0; 
        else cout<<" ";
        cout<<tree[r].data;
        inorder(tree[r].left);
    }
}
int main(){
    int n,i;
    char l,r;
    bool ischild[11]={false};
    cin>>n;
    
    for(i=0;i<n;i++){
        cin>>l>>r;
        tree[i].data=i;
        if(l=='-') tree[i].left=-1;
        else{
            tree[i].left=l-'0';
            ischild[l-'0']=true;
        }
        if(r=='-') tree[i].right=-1;
        else{
            tree[i].right=r-'0';
            ischild[r-'0']=true;
        }
    }
    for(i=0;i<n;i++){
        if(!ischild[i]){
            break;
        }
    }
    levelorder();
    flag=1;
    inorder(i);
}
