#include<iostream>
using namespace std;

int main(){
    int n, m, i, j, cnt = 0;
    cin >> n >> m;
    
    int piece[n+1];
    piece[0] = 0;
    for(i = 1; i <= n; i++){
        cin >> piece[i];
        piece[i] += piece[i-1];
    }
    for(i = 0; i < n; i++){
        for(j = i+1; j <= n; j++){
            if(piece[j] - piece[i] <= m) cnt++;
        }
    }
    cout << cnt;
    return 0;
}
