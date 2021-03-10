#include<string>
#include<iostream>
using namespace std;

bool isprime(int n){
    if(n == 0 || n == 1) return false;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    int L, k, i;
    string s;
    cin >> L >> k >> s;
    for(i = 0; i <= L-k; i++){
        if(isprime(stoi(s.substr(i, k)))){
            cout << s.substr(i, k) << endl;
            return 0;
        }
    }
    cout << "404" << endl;
    return 0;
}
