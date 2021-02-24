#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
    int n, i, j, ans = 0;
    cin >> n;
    int milk[n] = {0}, weight[n];
    for(i = 0; i < n; i++){
        cin >> weight[i];
        if(i){
            if(weight[i] > weight[i-1]) milk[i] = max(milk[i-1] + 100, milk[i]);
            else if(weight[i] == weight[i-1]) milk[i] = milk[i-1];
        }
        j = i - 1 ;
        while(j >=0 && weight[j] >= weight[j+1]){
            if(weight[j] > weight[j+1]) milk[j] = max(milk[j+1] + 100, milk[j]);
            else milk[j] = milk[j+1];
            j--;
        }
    }
    for(i = 0; i < n; i++){
        ans += milk[i];
    }
    cout << ans + 200 * n;
    return 0;
}
