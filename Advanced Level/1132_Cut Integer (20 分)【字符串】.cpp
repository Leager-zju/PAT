#include<iostream>
#include<string>
using namespace std;

int main(){
    string z;
    int n, A, B;
    cin >> n;
    while(n--){
        cin >> z;
        int len = z.length();
        A = stoi(z.substr(0, len/2));
        B = stoi(z.substr(len/2, len-len/2));
        if(A != 0 && B != 0 && stoi(z)%(A*B) == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
