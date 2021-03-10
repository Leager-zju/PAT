#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 10010

int line[maxn][maxn] = {0};
int mintran;
vector<int> temp, path;
vector<int> G[maxn];
vector<bool> visit(maxn, false);

void DFS(int start, int end){
    if(path.size() && temp.size() > path.size()) return;
    if(start == end){
        int cnt = 0;
        for(int i = 1; i < temp.size()-1; i++){
            if(line[temp[i-1]][temp[i]] != line[temp[i]][temp[i+1]]) cnt++;
        }
        if(path.size() == 0 || temp.size() < path.size() || (temp.size() == path.size() && cnt < mintran)){
            path = temp;
            mintran = cnt;
        }
        return;
    } else if(temp.size() == path.size()) return;
    
    for(int i = 0; i < G[start].size(); i++){
        if(visit[G[start][i]]) continue;
        visit[G[start][i]] = true;
        temp.push_back(G[start][i]);
        DFS(G[start][i], end);
        temp.pop_back();
        visit[G[start][i]] = false;
    }
}

int main(){
    int n, m, i, j, u, v;
    int q;
    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> m >> u;
        for(j = 1; j < m; j++){
            cin >> v;
            line[u][v] = line[v][u] = i;
            G[u].push_back(v);
            G[v].push_back(u);
            u = v;
        }
    }
    cin >> q;
    while(q--){
        cin >> u >> v;
        path.clear();
        temp.push_back(u);
        visit[u] = true;
        DFS(u, v);
        visit[u] = false;
        temp.pop_back();
        n = path.size()-1;
        i = 0;
        printf("%d\n", n);
        while(i < n){
            for(j = i+1; j < n; j++){
                if(line[path[j-1]][path[j]] != line[path[j]][path[j+1]]) break;   // j是中转站
            }
            printf("Take Line#%d from %04d to %04d.\n", line[path[j-1]][path[j]], path[i], path[j]);
            i = j;
        }
    }
    return 0;
}
