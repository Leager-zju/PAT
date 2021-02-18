#include<string>
#include<iostream>
using namespace std;

string renew(string s){
    string ans;
    int i,j;
    for(i=0;i<s.length();i++){
        for(j=i;j<s.length();j++){
            if(s[j]!=s[i]) break;
            count++;
        }
        ans+=s[j-1];
        ans+=(j-i+'0');
        i=j-1;
    }
    return ans;
}

int main(){
    int count;
    string s;
    cin>>s>>count;
    while(--count){
        s=renew(s);
    }
    cout<<s;
}
