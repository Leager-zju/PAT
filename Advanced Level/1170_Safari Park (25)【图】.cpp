#include<iostream>
#include<unordered_set>
using namespace std;

bool G[502][502] = {false};

int main(){
    int N, R, K, u, v, i, j, M;
    cin >> N >> R >> K;
    for(i = 0; i < R; i++){
        cin >> u >> v;
        G[u][v] = G[v][u] = true;
    }
    cin >> M;
    while(M--){
        int region[N + 1];
        int cnt = 0;
        unordered_set<int> species;
        for(i = 1; i <= N; i++){
            cin >> region[i];
            if(!species.count(region[i])){
                species.insert(region[i]);
                cnt++;
            }
        }
        if(cnt != K){
            if(cnt > K) cout << "Error: Too many species." << endl;
            else cout << "Error: Too few species." << endl;
            continue;
        }
        cnt = 0;
        for(i = 1; i < N; i++){
            if(cnt) break;
            for(j = i + 1; j <= N; j++){
                if(region[i] == region[j] && G[i][j]){
                    cnt = 1;
                    break;
                }
            }
        }
        if(cnt) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}
