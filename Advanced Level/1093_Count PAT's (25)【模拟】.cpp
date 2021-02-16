#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    
    int ans=0,i,j,len=s.length(),pnum=0,tnum=0;
    for(i=0;i<len;i++){
        if(s[i]=='P'){
            for(j=len-1;j>i;j--){
                if(s[j]=='T') tnum++;
            }
            pnum=1;
            for(j=i+1;j<len;j++){
                if(s[j]=='P') pnum++;
                else if(s[j]=='A') ans=(ans+pnum*tnum%1000000007)%1000000007;
                else if(s[j]=='T') tnum--;
            }
            break;
        }
    }
    cout<<ans;
}
