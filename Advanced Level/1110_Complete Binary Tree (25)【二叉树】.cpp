#include<cstdio>
#include<string.h>
#include<math.h>
#include<queue>
using namespace std;

struct node{
    int left,right,id;
}tree[25];

int isCBT(int root,int n){
    queue<node> Q;
    Q.push(tree[root]);
    int count=1,flag=0;
    node top;
    while(!Q.empty()){
        top=Q.front();
        Q.pop();
        if(count<=(n-1)/2 && (top.left==-1 || top.right==-1)) flag=1;
        if(count==n/2 && n%2==0 && (top.left==-1 || top.right!=-1)) flag=1;
        if(top.left!=-1) Q.push(tree[top.left]);
        if(top.right!=-1) Q.push(tree[top.right]);
        count++;
    }
    if(flag) return -1;
    else return top.id;
}

int main(){
    int n,i,root,flag;
    bool ischild[25]={false};
    char l[2],r[2];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s %s",l,r);
        tree[i].id=i;
        if(l[0]=='-') tree[i].left=-1;
        else{
            if(strlen(l)==1){
                tree[i].left=l[0]-'0';
                ischild[l[0]-'0']=true;
            }
            else{
                tree[i].left=(l[0]-'0')*10+(l[1]-'0');
                ischild[(l[0]-'0')*10+(l[1]-'0')]=true;
            }
        }
        if(r[0]=='-') tree[i].right=-1;
        else{
            if(strlen(r)==1){
                tree[i].right=r[0]-'0';
                ischild[r[0]-'0']=true;
            }
            else{
                tree[i].right=(r[0]-'0')*10+(r[1]-'0');
                ischild[(r[0]-'0')*10+(r[1]-'0')]=true;
            }
        }
    }
    for(i=0;i<n;i++){
        if(!ischild[i]){
            root=i;
            break;
        }
    }
    flag=isCBT(root,n);
    if(flag!=-1) printf("YES %d",flag);
    else printf("NO %d",root);
}
