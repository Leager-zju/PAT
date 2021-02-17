#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 10010

bool visited[maxn]={false};
vector<int> graph[maxn];
int depth[maxn]={0};
int maxdepth,n,m=0;

void DFS(int n,int depth){
    if(depth>maxdepth) maxdepth=depth;
    visited[n]=true;
    for(int i=0;i<graph[n].size();i++){
        if(!visited[graph[n][i]]) DFS(graph[n][i],depth+1);
    }
}

int main(){
    int u,v,i;
    scanf("%d",&n);
    for(i=1;i<=n-1;i++){
        scanf("%d %d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int count=0;
    for(i=1;i<=n;i++){
        if(visited[i]==false){
            count++;
            DFS(i,0);
        }
    }
    if(count>1){
        printf("Error: %d components",count);
        return 0;
    }
    for(i=1;i<=n;i++){
        maxdepth=0;
        fill(visited+1,visited+n+1,false);
        DFS(i,1);
        depth[i]=maxdepth;
        if(maxdepth>m) m=maxdepth;
    }
    for(i=1;i<=n;i++){
        if(depth[i]==m) printf("%d\n",i);
    }
    
}
