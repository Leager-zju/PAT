#include<string>
#include<iostream>
using namespace std;

string transform(string s){
    int i = 0, j;
    string ans;
    while(i < s.length()){
        int cnt = 0;
        for(j = i; j < s.length(); j++){
            if(s[j] == s[i]) cnt++;
            else break;
        }
        ans.push_back(s[i]);
        ans.push_back(cnt + '0');
        i = j;
    }
    return ans;
}

int main(){
    int n, D;
    cin >> n >> D;
    string s = to_string(n);
    while(--D){
        s = transform(s);
    }
    cout << s << endl;
    return 0;
}
