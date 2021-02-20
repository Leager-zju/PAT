#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 1020
#define INF 10000007

struct info{
    int end;
    double len;
}temp;

struct station{
    string id;
    double avdis=0.0,mind=INF;
}s[12];

bool visited[maxn];
double dis[maxn];
vector<info> G[maxn];
int n,m,k,ds;
 
void dijkstra(int x){
    fill(dis+1,dis+n+m+1,INF);
    fill(visited+1,visited+n+m+1,false);
    dis[x]=0;
    int i,j;
    for(i=1;i<=n+m+1;i++){
        int u=-1,min=INF;
        for(j=1;j<=n+m;j++){
            if(dis[j]<min && !visited[j]){
                min=dis[j];
                u=j;
            }
        }
        if(u==-1) break;
        visited[u]=true;
        for(j=0;j<G[u].size();j++){
            int v=G[u][j].end;
            if(dis[u]+G[u][j].len<dis[v] && !visited[v]){
                dis[v]=dis[u]+G[u][j].len;
            }
        }
    }
    i=x-n;
    for(j=1;j<=n;j++){
        if(dis[j]>ds){
            s[i].avdis=INF;
            s[i].mind=INF;
            return;
        }
        s[i].avdis+=dis[j];
        s[i].mind=min(dis[j],s[i].mind);
    }
    s[i].avdis/=n;
}

int transform(string s){
    int ans=0,i;
    if(s[0]=='G') return n+transform(s.substr(1));
    for(i=0;i<s.length();i++){
        ans=ans*10+(s[i]-'0');
    }
    return ans;
}
int main(){
    string start,end;
    int u,v,i,ans=-1;
    double ans_min=0,ans_avr=INF;
    cin>>n>>m>>k>>ds;
    for(i=0;i<k;i++){
        cin>>start>>end>>temp.len;
        u=transform(start);
        v=transform(end);
        temp.end=v;
        G[u].push_back(temp);
        temp.end=u;
        G[v].push_back(temp);
    }
    for(i=1;i<=m;i++){
        s[i].id="G"+to_string(i);
        dijkstra(i+n);
        if(s[i].mind==INF) continue;
        if(s[i].mind>ans_min || (s[i].mind==ans_min && s[i].avdis<ans_avr)){
            ans_min=s[i].mind;
            ans_avr=s[i].avdis;
            ans=i;
        }
    }
    if(ans==-1) printf("No Solution");
    else printf("%s\n%.1f %.1f",s[ans].id.c_str(),ans_min,ans_avr);
}
