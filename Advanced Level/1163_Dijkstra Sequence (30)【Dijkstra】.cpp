#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define inf 10e7
#define maxn 1011

struct node{
    int end, len;
};

vector<node> G[maxn];
int dis[maxn];
bool visit[maxn];
int Nv, Ne;

void Dijkstra(int start){
    fill(dis + 1, dis + Nv + 1, inf);
    fill(visit + 1, visit + Nv + 1, false);
    dis[start] = 0;
    
    for(int i = 0; i < Nv; i++ ){
        int u = -1, min = inf;
        for(int j = 1; j <= Nv; j++){
            if(!visit[j] && dis[j] < min){
                u = j;
                min = dis[j];
            }
        }
        if(u == -1) return;
        visit[u] = true;
        for(int j = 0; j < G[u].size(); j++){
            int v = G[u][j].end;
            if(dis[u] + G[u][j].len < dis[v]){
                dis[v] = dis[u] + G[u][j].len;
            }
        }
    }
}

bool judge(vector<int> path){
    for(int i = 0; i < path.size() - 1; i++){
        if(dis[path[i]] > dis[path[i + 1]]) return false;
    }
    return true;
}

int main(){
    int u, v, len, i, k;
    cin >> Nv >> Ne;
    for(i = 0; i < Ne; i++){
        cin >> u >> v >> len;
        G[u].push_back({v, len});
        G[v].push_back({u, len});
    }
    cin >> k;
    while(k--){
        vector<int> path(Nv);
        for(i = 0; i < Nv; i++){
            cin >> path[i];
        }
        Dijkstra(path[0]);
        if(judge(path)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
