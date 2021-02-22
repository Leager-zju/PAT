#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int father[1011];
int R[1011][1011] = {0};

int findfather(int n){
    int a = n;
    while(n != father[n]){
        n = father[n];
    }
    while(a != n){
        int temp = a;
        a = father[a];
        father[temp] = n;
    }
    return n;
}
void Union(int x, int y){
    int fx = findfather(x);
    int fy = findfather(y);
    if(fx != fy) father[fx] = fy; 
}

int main(){
    int K, N, M, i, j, u, v, time;
    
    scanf("%d %d %d", &K, &N, &M);
    bool visit[N + 1] = {false};
    vector<int> suspect;
    
    for(i = 0; i < M; i++){
        scanf("%d %d %d", &u, &v, &time);
        R[u][v] += time;
    }
    for(i = 1; i <= N; i++){
        double count = 0.0, callback = 0.0;
        father[i] = i;
        for(j = 1; j <= N; j++){
            if(R[i][j] <= 5 && R[i][j]){
                count++;
                if(R[j][i]) callback++;
            }
        }
        if(count > K && callback/count <= 0.2) suspect.push_back(i);
    }
    
    if(suspect.size() == 0){
        printf("None");
        return 0;
    }
    
    for(i = 0; i < suspect.size(); i++){
        for(j = i + 1; j < suspect.size(); j++){
            if(R[suspect[i]][suspect[j]] && R[suspect[j]][suspect[i]]) Union(suspect[i], suspect[j]);
        }
    }
    for(i = 0; i < suspect.size(); i++){
        if(!visit[suspect[i]]){
            printf("%d", suspect[i]);
            visit[suspect[i]] = true;
        }
        else continue;
        for(j = i + 1; j < suspect.size(); j++){
            if(findfather(suspect[j]) == findfather(suspect[i])){
                printf(" %d", suspect[j]);
                visit[suspect[j]] = true;
            }
        }
        printf("\n");
    }
    return 0;
}
