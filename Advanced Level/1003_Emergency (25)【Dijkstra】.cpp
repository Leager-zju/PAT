#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define maxn 520
#define INF 10e7

struct node{
    int v,length;
};

int n,m,c1,c2;
int dis[maxn],num[maxn]={0},weight[maxn]={0},w[maxn];
bool Isvisited[maxn]={false};
vector<node> A[maxn];

void search(int start){
    fill(dis,dis+maxn,INF);
    dis[start]=0;
    num[start]=1;
    weight[start]=w[start];
    for(int i=0;i<n;i++){
        int u=-1,min=INF;
        for(int j=0;j<n;j++){
            if(dis[j]<min && !Isvisited[j]){
                min=dis[j];
                u=j;
            }
        }
        if(min==INF) return;
        Isvisited[u]=true;
        for(int j=0;j<A[u].size();j++){
            int get=A[u][j].v;
            if(dis[u]+A[u][j].length < dis[get]){
                dis[get]=dis[u]+A[u][j].length;
                num[get]=num[u];
                weight[get]=weight[u]+w[get];
            }
            else if(dis[u]+A[u][j].length==dis[get]){
                if(weight[u]+w[get]>weight[get]) weight[get]=weight[u]+w[get];
                num[get]+=num[u];
            }
        }    
    }
}
int main(){
    int i,a,b,len;
    cin>>n>>m>>c1>>c2;
    for(i=0;i<n;i++){
        cin>>w[i];
    }
    for(i=0;i<m;i++){
        node p,q;
        cin>>a>>b>>len;
        p.v=b;
        q.v=a;
        p.length=q.length=len;
        A[a].push_back(p);
        A[b].push_back(q);
    }
    search(c1);
    cout<<num[c2]<<" "<<weight[c2];
}
