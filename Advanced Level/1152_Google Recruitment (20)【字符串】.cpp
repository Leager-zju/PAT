#include<string>
#include<iostream>
using namespace std;

bool isprime(long long n){
    if(n==0||n==1) return false;
    for(int i=2;i*i<=n;i++){
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
    int L,k;
    string s,subnum;
    cin>>L>>k;
    cin>>s;
    for(i=0;i<=L-k;i++){
        subnum=s.substr(i,k);
        if(isprime(str_int(subnum))){
            cout<<subnum<<endl;
            return 0;
        }
    }
    cout<<"404"<<endl;
    return 0;
}
