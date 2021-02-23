#include<unordered_set>
#include<vector>
#include<iostream>
using namespace std;

int main(){
    int u, v;
    int n, m, i, j;
    int flag, cnt = 0;
    unordered_set<int> number;
    
    cin >> u >> v >> n >> m;

    number.insert(u);
    number.insert(v);
    
    int give[n + 1][m + 1];
    bool isout[n + 1] = {false};
    
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            cin >> give[i][j];
        }
    }
    for(i = 1; i <= m; i++){
        vector<int> outmember;
        for(j = 1; j <= n; j++){
            if(isout[j]) continue;
            flag = 1;
            for(auto it : number){
                if(number.count(give[j][i] + it)){
                    flag = 0;
                    break;
                }
            }
            if(number.count(give[j][i]) || flag){
                outmember.push_back(j);
                isout[j] = true;
                cnt++;
            }
            else number.insert(give[j][i]);
        }
        
        for(j = 0; j < outmember.size(); j++){
            cout << "Round #" << i << ": " << outmember[j] << " is out." << endl;
        }
    }
    
    if(cnt != n){
        cout << "Winner(s):";
        for(i = 1; i <= n; i++){
            if(!isout[i]) cout << " " << i;
        }
        cout << endl;
    }
    else cout << "No winner." << endl;
}
