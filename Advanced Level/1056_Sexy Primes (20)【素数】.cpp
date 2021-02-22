#include<iostream>
using namespace std;

bool isprime(int n){
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

bool issexyprime(int n){
    return isprime(n) && (isprime(n - 6) || isprime(n + 6));
}

int main(){
    int n;
    cin >> n;
    if(issexyprime(n)){
        if(isprime(n - 6)){
            cout << "Yes" << endl;
            cout << n - 6;
        } else if(isprime(n + 6)){
            cout << "Yes" << endl;
            cout << n + 6;
        }
    } else {
        while(!issexyprime(n)){
            n++;
        }
        cout << "No" << endl;
        cout << n;
    }
}
