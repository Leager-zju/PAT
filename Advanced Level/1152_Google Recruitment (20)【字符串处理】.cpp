#include<string>
#include<iostream>
#include<cmath>
using namespace std;

bool isprime(long long n){
    if(n==0||n==1) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}

long long str_int(string s){
    long long ans=0;
    for(int i=0;i<s.length();i++){
        ans=ans*10+(s[i]-'0');
    }
    return ans;
}

int main(){
    int L,k,i=0;
    string s,subnum;
    cin>>L>>k;
    cin>>s;
    subnum=s.substr(i,k);
    while(!isprime(str_int(subnum)) && i<=L-k){
        i++;
        subnum=s.substr(i,k);
    }
    if(i<=L-k) cout<<subnum<<endl;
    else cout<<"404"<<endl;
}
