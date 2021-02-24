#include<vector>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;

struct node{
    int S, D;
};

node edge[1011][1011];
vector<int> Next[1011];
int indegree[1011] = {0}, id[1011] = {0}, weightS[1011] = {0}, weightD[1011] = {0}, Pre[1011];

int main(){
    int n, m, k, u, v, i, j, flag = 0, cnt = 0;
    queue<int> Q;
    
    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        scanf("%d %d", &edge[u][v].S, &edge[u][v].D);
        Next[u].push_back(v);
        indegree[v]++;
        id[v]++;
    }
    for(i = 0; i < n; i++){
        if(indegree[i] == 0) Q.push(i);
    }
    fill(Pre, Pre + n, -1);
    while(!Q.empty()){
        u = Q.front();
        cnt++;
        Q.pop();
        for(i = 0; i < Next[u].size(); i++){
            v = Next[u][i];
            indegree[v]--;
            if(indegree[v] == 0) Q.push(v);
            if(Pre[v] == -1 || weightS[u] + edge[u][v].S < weightS[v]){
                weightS[v] = weightS[u] + edge[u][v].S;
                weightD[v] = weightD[u] + edge[u][v].D;
                Pre[v] = u;
            }
            else if(weightS[u] + edge[u][v].S == weightS[v] && weightD[u] + edge[u][v].D > weightD[v]){
                weightD[v] = weightD[u] + edge[u][v].D;
                Pre[v] = u;
            }
        }
    }
    if(cnt != n) flag = 1;
    if(flag) printf("Impossible.\n");
    else printf("Okay.\n");
    
    scanf("%d", &k);
    while(k--){
        scanf("%d", &u);
        if(id[u] == 0) printf("You may take test %d directly.\n", u);
        else if(flag) printf("Error.\n");
        else{
            vector<int> path;
            while(u != -1){
                path.push_back(u);
                u = Pre[u];
            }
            for(i = path.size() - 1; i >= 0; i--){
                if(i) printf("%d->", path[i]);
                else printf("%d\n", path[i]);
            }
        }
    }
    return 0;
}
