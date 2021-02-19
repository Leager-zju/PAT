#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
#define inf 10e7
#define maxn 520

struct info{
    int arrive,distance,t;
};

int dis[maxn],time[maxn],dispre[maxn];
bool visited[maxn];
vector<info> graph[maxn];
vector<int> temppath,shortestpath,fastestpath,timepre[maxn];

void findshortestpath(int s,int n){
    fill(dis,dis+n,inf);
    fill(time,time+n,inf);
    fill(visited,visited+n,false);
    dis[s]=time[s]=0;
    int u,v,min,i,j;
    for(i=0;i<n;i++){
        u=-1,min=inf;
        for(j=0;j<n;j++){
            if(!visited[j] && dis[j]<min){
                min=dis[j];
                u=j;
            }
        }
        if(u==-1) return;
        visited[u]=true;
        for(j=0;j<graph[u].size();j++){
            v=graph[u][j].arrive;
            if(dis[u]+graph[u][j].distance<dis[v]){
                dis[v]=dis[u]+graph[u][j].distance;
                time[v]=time[u]+graph[u][j].t;
                dispre[v]=u;
            }
            else if(dis[u]+graph[u][j].distance==dis[v] && time[u]+graph[u][j].t<time[v]){
                time[v]=time[u]+graph[u][j].t;
                dispre[v]=u;
            }
        }
    }
}

void findfastestpath(int s,int n){
    fill(dis,dis+n,inf);
    fill(time,time+n,inf);
    fill(visited,visited+n,false);
    dis[s]=time[s]=0;
    int i,j,u,v,min;
    for(i=0;i<n;i++){
        u=-1,min=inf;
        for(int j=0;j<n;j++){
            if(!visited[j] && time[j]<min){
                min=time[j];
                u=j;
            }
        }
        if(u==-1) return;
        visited[u]=true;
        for(j=0;j<graph[u].size();j++){
            v=graph[u][j].arrive;
            if(time[u]+graph[u][j].t<time[v]){
                time[v]=time[u]+graph[u][j].t;
                timepre[v].clear();
                timepre[v].push_back(u);
            }
            else if(time[u]+graph[u][j].t==time[v]) timepre[v].push_back(u);
        }
    }
}

void dispath(int u,int v){
    while(u!=v){
        shortestpath.push_back(u);
        u=dispre[u];
    }
    shortestpath.push_back(v);
}

void timepath(int u,int v){
    if(u==v){
        if(fastestpath.size()==0 || temppath.size()<fastestpath.size()) fastestpath=temppath;
        return;
    }
    for(int i=0;i<timepre[u].size();i++){
        temppath.push_back(timepre[u][i]);
        timepath(timepre[u][i],v);
        temppath.pop_back();
    }
}

int main(){
    int n,m,start,end;
    int i,u,v,len,t,flag;
    info a,b;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d %d %d %d",&u,&v,&flag,&len,&t);
        if(flag){
            a.arrive=v;
            a.distance=len;
            a.t=t;
            graph[u].push_back(a);
        }
        else{
            a.arrive=v;
            b.arrive=u;
            a.distance=b.distance=len;
            a.t=b.t=t;
            graph[u].push_back(a);
            graph[v].push_back(b);
        }
    }
    scanf("%d %d",&start,&end);
    
    findshortestpath(start,n);
    u=dis[end];
    dispath(end,start);
    
    findfastestpath(start,n);
    v=time[end];
    temppath.push_back(end);
    timepath(end,start);
    
    if(fastestpath==shortestpath){
        printf("Distance = %d; Time = %d:",u,v);
        for(i=shortestpath.size()-1;i>=0;i--){
            printf(" %d",shortestpath[i]);
            if(i!=0) printf(" ->");
        }
    }
    else{
        printf("Distance = %d:",u);
        for(i=shortestpath.size()-1;i>=0;i--){
            printf(" %d",shortestpath[i]);
            if(i!=0) printf(" ->");
        }
        printf("\n");
        printf("Time = %d:",v);
        for(i=fastestpath.size()-1;i>=0;i--){
            printf(" %d",fastestpath[i]);
            if(i!=0) printf(" ->");
        }
    }
}
