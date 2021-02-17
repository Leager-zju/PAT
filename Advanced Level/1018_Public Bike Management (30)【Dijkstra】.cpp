#include<vector>
#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;
#define maxn 502
#define INF 1000007

struct edge{
    int end,len;
}a,b;

vector<edge> Graph[maxn];
vector<int> pre[maxn],minpath,temppath;
int dis[maxn],num[maxn],Cmax,n,Sp,m;
int minBring=INF,minTake=INF;
bool visited[maxn]={false};

void Dijkstra(){
    fill(dis+1,dis+1+n,INF);
    dis[0]=0;
    for(int i=0;i<=n;i++){
        int u=-1,min=INF;
        for(int j=0;j<=n;j++){
            if(dis[j]<min && !visited[j]){
                min=dis[j];
                u=j;
            }
        }
        if(u==-1) break;
        visited[u]=true;
        for(int p=0;p<Graph[u].size();p++){
            int v=Graph[u][p].end;
            if(dis[v]>dis[u]+Graph[u][p].len){
                dis[v]=dis[u]+Graph[u][p].len;
                pre[v].clear();
                pre[v].push_back(u);
            }
            else if(dis[v]==dis[u]+Graph[u][p].len){
                pre[v].push_back(u);
            }
        }
    }
}

void DFS(int end){
    if(end==0){
        int bring=0,take=0;
        for(int i=temppath.size()-1;i>=0;i--){
            if(num[temppath[i]]>Cmax/2) take+=num[temppath[i]]-Cmax/2;
            else if(Cmax/2-num[temppath[i]]>take){
                bring+=Cmax/2-num[temppath[i]]-take;
                take=0;
            }
            else take-=Cmax/2-num[temppath[i]];
        }
        if(bring<minBring){
            minpath=temppath;
            minBring=bring;
            minTake=take;
        }
        else if(bring==minBring && take<minTake){
            minpath=temppath;
            minTake=take;
        }
        return;
    }
    temppath.push_back(end);
    for(int i=0;i<pre[end].size();i++){
        DFS(pre[start][i]);
    }
    temppath.pop_back();
}
int main(){
    int i,start,end,len;;
    cin>>Cmax>>n>>Sp>>m;
    for(i=1;i<=n;i++){
        cin>>num[i];
    }
    for(i=1;i<=m;i++){
        cin>>start>>end>>len;
        a.end=end;
        b.end=start;
        a.len=b.len=len;
        Graph[start].push_back(a);
        Graph[end].push_back(b);
    }
    Dijkstra();
    DFS(Sp);
    cout<<minBring<<" "<<"0";
    for(i=minpath.size()-1;i>=0;i--){
        cout<<"->"<<minpath[i];
    }
    cout<<" "<<minTake;
}
