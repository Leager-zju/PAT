#include<iostream>
#include<string>
using namespace std;

int strtonum(string s){
    int ans=0;
    for(int i=0;i<s.length();i++){
        ans=ans*10+(s[i]-'0');
    }
    return ans;
}

int main(){
    string z,a,b;
    int n,A,B;
    cin>>n;
    while(n--){
        cin>>z;
        int len=z.length();
        a=z.substr(0,len/2);
        b=z.substr(len/2,len-len/2);
        A=strtonum(a);
        B=strtonum(b);
        if(A==0 || B==0) cout<<"No"<<endl;        // 特殊情况 0不能被除
        else{
            if(strtonum(z)%(A*B)==0) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
}
