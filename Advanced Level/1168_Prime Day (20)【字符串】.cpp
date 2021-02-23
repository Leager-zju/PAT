#include<string>
#include<iostream>
using namespace std;

bool isprime(string s){
    int n = 0, i;
    for(i = 0; i < s.length(); i++){
        n = n * 10 + (s[i] - '0');
    }
    if(n == 0 || n == 1) return false;
    for(i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    int flag = 1;
    string s;
    cin >> s;
    while(s.length()){
        cout << s << " ";
        if(isprime(s)) cout << "Yes" << endl;
        else{
            cout << "No" << endl;
            flag = 0;
        }
        s = s.substr(1);
    }
    if(flag) cout << "All Prime!" << endl;
    return 0;
}
