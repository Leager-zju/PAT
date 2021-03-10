#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m, i, j, flag;
    cin >> n;
    while(n--){
        cin >> m;
        vector<int> queen(m);
        flag = 0;
        for(i = 0; i < m; i++){
            cin >> queen[i];
            if(flag) continue;
            for(j = 0; j < i; j++){
                if(queen[i] == queen[j] || queen[i] - queen[j] == i - j || queen[j] - queen[i] == i - j){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
