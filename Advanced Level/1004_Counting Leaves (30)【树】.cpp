#include<vector>
#include<queue>
#include<cstdio>
using namespace std;

struct info{
    vector<int> child;
    int layer;
}node[103],top;

int main(){
    int n,m,i,j;
    int num[103]={0};
    int root,k,son;
    queue<info> tree;
    scanf("%d %d",&n,&m);
    
    if(n==0) return 0;
    
    node[1].layer=1;
    for(i=0;i<m;i++){
        scanf("%d %d",&root,&k);
        for(j=0;j<k;j++){
            scanf("%d",&son);
            node[root].child.push_back(son);
        }
    }
    tree.push(node[1]);
    while(!tree.empty()){
        top=tree.front();
        tree.pop();
        if(top.child.size()==0) num[top.layer]++;
        else{
            for(i=0;i<top.child.size();i++){
                node[top.child[i]].layer=top.layer+1;
                tree.push(node[top.child[i]]);
            }
        }
    }
    printf("%d",num[1]);
    for(i=2;i<=top.layer;i++){
        printf(" %d",num[i]);
    }
}
