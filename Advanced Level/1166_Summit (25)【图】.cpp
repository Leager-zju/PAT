#include<iostream>
#include<vector>
using namespace std;
#define maxn 211

int G[maxn][maxn] = {0};

int main(){
    int N, M, i, j, u, v;
    int K, L, Case, flag;
    cin >> N >> M;
    for(i = 0; i < M; i++){
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }
    
    cin >> K;
    for(Case = 1; Case <= K; Case++){
        cin >> L;
        vector<int> area(L);
        bool visit[N + 1] = {false};
        flag = 0;
        for(i = 0; i < L; i++){
            cin >> area[i];
            visit[area[i]] = true;
            if(flag) continue;
            for(j = 0; j < i; j++){
                if(!G[area[j]][area[i]]){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag) cout << "Area " << Case << " needs help." << endl;
        else{
            for(i = 1; i <= N; i++){
                if(!visit[i]){
                    for(j = 0; j < L; j++){
                        if(!G[i][area[j]]) break;
                    }
                }
                if(j == L) break;
            }
            if(j == L) cout << "Area " << Case << " may invite more people, such as " << i << "." << endl;
            else cout << "Area " << Case << " is OK." << endl;
        }
    }
}
