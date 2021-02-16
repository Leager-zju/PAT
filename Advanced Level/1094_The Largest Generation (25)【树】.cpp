#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

struct info{
    int floor;
    vector<int> child;
}member[110],top;



int main(){
    int n,m;
    int i,j,father,num,maxg=1,maxi=1,son;
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
    generation[1]=1;
    Q.push(member[1]);
    while(!Q.empty()){
        top=Q.front();
        Q.pop();
        for(i=0;i<top.child.size();i++){
            int u=top.child[i];
            member[u].floor=top.floor+1;
            j=member[u].floor;
            generation[j]++;
            if(generation[j]>maxg){
                maxg=generation[j];
                maxi=j;
            }
            Q.push(member[u]);
        }
    }
    printf("%d %d",maxg,maxi);
}
