#include<string>
#include<iostream>
using namespace std;

string renew(string s){
    string ans;
    int i,j,count;
    for(i=0;i<s.length();i++){
        count=0;
        for(j=i;j<s.length();j++){
            if(s[j]!=s[i]) break;
            count++;
        }
        i=j-1;
        ans+=s[i];
        ans+=(count+'0');
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
