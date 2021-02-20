#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

struct info{
    int floor;
    vector<int> child;
}member[110],top;

int main(){
    int n,m,i,j,father,son,num;
    int maxg=1,maxi=1;
    int generation[110]={0};
    
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d",&father,&num);
        for(j=0;j<num;j++){
            scanf("%d",&son);
            member[father].child.push_back(son);
        }
    }
    
    queue<info> Q;
    member[1].floor=1;
    Q.push(member[1]);
    while(!Q.empty()){
        top=Q.front();
        Q.pop();
        generation[top.floor]++;
        if(generation[top.floor]>maxg){
            maxg=generation[top.floor];
            maxi=top.floor;
        }
        for(i=0;i<top.child.size();i++){
            int u=top.child[i];
            member[u].floor=top.floor+1;
            Q.push(member[u]);
        }
    }
    printf("%d %d\n",maxg,maxi);
}
