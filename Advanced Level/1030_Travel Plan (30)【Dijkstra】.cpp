#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 520
#define INF 10e7

struct node{
    int end,distance,cost;
}p,q;

int n,m,s,d;
int dis[maxn],cost[maxn],pre[maxn];
bool Isvisited[maxn]={false};
vector<node> P[maxn];
vector<int> path,temppath;

void search(int start){
    fill(dis,dis+maxn,INF);
    fill(cost,cost+maxn,INF);
    dis[start]=0;
    cost[start]=0;
    for(int i=0;i<n;i++){
        int u=-1,min=INF;
        for(int j=0;j<n;j++){
            if(dis[j]<min && !Isvisited[j]){
                min=dis[j];
                u=j;
            }
        }
        if(u==-1) return;
        Isvisited[u]=true;
        for(int j=0;j<P[u].size();j++){
            int v=P[u][j].end;
            if(dis[u]+P[u][j].distance<dis[v]){
                dis[v]=dis[u]+P[u][j].distance;
                cost[v]=cost[u]+P[u][j].cost;
                pre[v]=u;
            }
            else if(dis[u]+P[u][j].distance==dis[v] && cost[u]+P[u][j].cost<cost[v]){
                cost[v]=cost[u]+P[u][j].cost;
                pre[v]=u;
            }
        }
    }
}
int main(){
    int start,end,len,c,i;
    cin>>n>>m>>s>>d;
    for(i=0;i<m;i++){
        cin>>start>>end>>len>>c;
        p.end=end;
        q.end=start;
        p.distance=q.distance=len;
        p.cost=q.cost=c;
        P[start].push_back(p);
        P[end].push_back(q);
    }
    search(s);
    start=s,end=d;
    path.push_back(end);
    while(start!=end){
        end=pre[end];
        path.push_back(end);
    }
    for(i=path.size()-1;i>=0;i--){
        cout<<path[i]<<" ";
    }
    cout<<dis[d]<<" "<<cost[d];
}
