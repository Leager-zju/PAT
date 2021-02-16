#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
#define maxn 202
#define INF 10000007

struct info{
    int destination,len;
}temp;

map<string,int> StoI;
map<int,string> ItoS;

bool visited[maxn];
int dis[maxn],total[maxn],minpath[maxn];
int happiness[maxn];
vector<info> G[maxn];
vector<int> pre[maxn],path,temppath;
int n,k;

void visit(int start){
    fill(dis,dis+n,INF);
    fill(visited,visited+n,false);
    fill(total,total+n,0);
    fill(minpath,minpath+n,0);
    
    dis[start]=0;
    minpath[start]=1;
    for(int i=0;i<n;i++){
        int u=-1,mindis=INF;
        for(int j=0;j<n;j++){
            if(dis[j]<mindis && visited[j]==false){
                u=j;
                mindis=dis[j];
            }
        }
        if(u==-1) return;
        visited[u]=true;
        for(int j=0;j<G[u].size();j++){
            int v=G[u][j].destination;
            if(dis[u]+G[u][j].len<dis[v]){
                dis[v]=dis[u]+G[u][j].len;
                pre[v].clear();
                pre[v].push_back(u);
                minpath[v]=minpath[u];
                total[v]=total[u]+happiness[v];
            }
            else if(dis[u]+G[u][j].len==dis[v]){
                if(total[u]+happiness[v]>total[v]){
                    pre[v].clear();
                    pre[v].push_back(u);
                    total[v]=total[u]+happiness[v];
                }
                else if(total[u]+happiness[v]==total[v]) pre[v].push_back(u);
                minpath[v]+=minpath[u];
            }
        }
    }
}

void DFS(int end){
    if(end==0 && (path.size()==0 || path.size()>temppath.size())){
        path=temppath;
        return;
    }
    for(int i=0;i<pre[end].size();i++){
        temppath.push_back(pre[end][i]);
        DFS(pre[end][i]);
        temppath.pop_back();
    }
}

int main(){
    string u,v,start,city1,city2;
    int i;
    cin>>n>>k>>start;
    StoI[start]=0;
    ItoS[0]=start;
    happiness[0]=0;
    for(i=1;i<n;i++){
        cin>>city1;
        StoI[city1]=i;
        ItoS[i]=city1;
        cin>>happiness[i];
    }
    for(i=0;i<k;i++){
        cin>>city1>>city2>>temp.len;
        int u=StoI[city1],v=StoI[city2];
        temp.destination=v;
        G[u].push_back(temp);
        temp.destination=u;
        G[v].push_back(temp);
    }

    visit(StoI[start]);

    int end=StoI["ROM"];
    temppath.push_back(end);
    DFS(end);

    int num=path.size()-1;
    cout<<minpath[end]<<" "<<dis[end]<<" "<<total[end]<<" "<<total[end]/num<<endl;
    cout<<start;
    for(i=num-1;i>=0;i--){
        cout<<"->"<<ItoS[path[i]];
    }
}
