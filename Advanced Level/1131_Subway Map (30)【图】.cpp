#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
#define maxn 10010
#define inf 10e7

vector<int> graph[maxn];
int G[maxn][maxn]={0};
bool visit[maxn]={false};
int mintran;
vector<int> path,temppath;

void makepath(int start,int end){
    if(temppath.size()>path.size() && path.size()!=0) return;
    if(start==end){
        int count=0;
        bool transfer[101]={false};
        for(int i=0;i<temppath.size()-1;i++){
            if(transfer[G[temppath[i]][temppath[i+1]]]){
                continue;
            }
            transfer[G[temppath[i]][temppath[i+1]]]=true;
            count++;
        }
        if(path.size()==0){
            path=temppath;
            mintran=count;
        }
        else if(temppath.size()<path.size() || ( temppath.size()==path.size() && mintran>count )){
            path=temppath;
            mintran=count;
        }
        return;
    }
    for(int i=0;i<graph[start].size();i++){
        int u=graph[start][i];
        if(visit[u]) continue;
        temppath.push_back(u);
        visit[u]=true;
        makepath(u,end);
        visit[u]=false;
        temppath.pop_back();
    }
}

int main(){
    int i,j,n,k,last,next;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&k,&last);
        for(j=1;j<k;j++){
            scanf("%d",&next);
            G[last][next]=G[next][last]=i;
            graph[last].push_back(next);
            graph[next].push_back(last);
            last=next;
        }
    }
    scanf("%d",&k);
    while(k--){
        scanf("%d %d",&last,&next);
        mintran=inf;
        temppath.clear();
        path.clear();
        temppath.push_back(last);
        visit[last]=true;
        makepath(last,next);
        visit[last]=false;
        
        j=0;
        int stops=path.size()-1;
        printf("%d\n",stops);
        while(j<stops){
            i=j+1;
            while(i<stops && G[path[i]][path[i+1]]==G[path[i]][path[i-1]]){
                i++;
            }
            printf("Take Line#%d from %04d to %04d.\n",G[path[i]][path[i-1]],path[j],path[i]);
            j=i;
        }
    }
}
