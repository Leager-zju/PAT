#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 502
#define inf 10e7

struct node{
    int end, len, time;
};

vector<bool> visit(maxn);
vector<node> G[maxn];
vector<int> temp, path1, path2, pre1(maxn), pre2[maxn];
vector<int> L(maxn), T(maxn);
int n, m;

void Dij1(int start){
    fill(visit.begin(), visit.end(), false);
    fill(L.begin(), L.end(), inf);
    fill(T.begin(), T.end(), inf);
    L[start] = T[start] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, min = inf;
        for(int j = 0; j < n; j++){
            if(!visit[j] && L[j] < min){
                u = j;
                min = L[j];
            }
        }
        if(u == -1) return;
        visit[u] = true;
        for(int j = 0; j < G[u].size(); j++){
            int v = G[u][j].end;
            if(L[v] > L[u] + G[u][j].len || (L[v] == L[u] + G[u][j].len && T[v] > T[u] + G[u][j].time)){
                L[v] = L[u] + G[u][j].len;
                T[v] = T[u] + G[u][j].time;
                pre1[v] = u;
            }
        }
    }
}
void Dij2(int start){
    fill(visit.begin(), visit.end(), false);
    fill(T.begin(), T.end(), inf);
    T[start] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, min = inf;
        for(int j = 0; j < n; j++){
            if(!visit[j] && T[j] < min){
                u = j;
                min = T[j];
            }
        }
        if(u == -1) return;
        visit[u] = true;
        for(int j = 0; j < G[u].size(); j++){
            int v = G[u][j].end;
            if(T[v] > T[u] + G[u][j].time){
                T[v] = T[u] + G[u][j].time;
                pre2[v].clear();
                pre2[v].push_back(u);
            }
            else if(T[v] == T[u] + G[u][j].time) pre2[v].push_back(u);
        }
    }
}
void DFS1(int start, int end){
    if(start == end){
        path1 = temp;
        return;
    }
    temp.push_back(pre1[end]);
    DFS1(start, pre1[end]);
    temp.pop_back();
}
void DFS2(int start, int end){
    if(start == end){
        if(path2.size() == 0 || temp.size() < path2.size()) path2 = temp;
    }
    for(int i = 0; i < pre2[end].size(); i++){
        temp.push_back(pre2[end][i]);
        DFS2(start, pre2[end][i]);
        temp.pop_back();
    }
}

int main(){
    int i, u, v, tag, l, t;
    cin >> n >> m;
    for(i = 0; i < m; i++){
        cin >> u >> v >> tag >> l >> t;
        G[u].push_back({v, l, t});
        if(tag == 0) G[v].push_back({u, l, t});
    }
    cin >> u >> v;
    temp.push_back(v);
    Dij1(u);
    DFS1(u, v);
    Dij2(u);
    DFS2(u, v);
    if(path1 == path2){
        cout << "Distance = " << L[v] << "; Time = " << T[v] << ": ";
        for(i = path1.size()-1; i >= 0; i--){
            cout << path1[i];
            if(i) cout << " -> ";
            else cout << endl;
        }
    } else {
        cout << "Distance = " << L[v] << ": ";
        for(i = path1.size()-1; i >= 0; i--){
            cout << path1[i];
            if(i) cout << " -> ";
            else cout << endl;
        }
        cout <<  "Time = " << T[v] << ": ";
        for(i = path2.size()-1; i >= 0; i--){
            cout << path2[i];
            if(i) cout << " -> ";
            else cout << endl;
        }
    }
    return 0;
}
