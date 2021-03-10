#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, i;
    cin >> n;
    vector<int> list(n+1);
    for(i = 1; i <= n; i++){
        cin >> list[i];
    }
    for(i = 1; i <= n; i++){
        while(list[i] > 0 && list[i] <= n && list[i] != i && list[i] != list[list[i]]){
            swap(list[i], list[list[i]]);
        }
    }
    for(i = 1; i <= n; i++){
        if(list[i] != i) break;
    }
    cout << i;
    return 0;
}
