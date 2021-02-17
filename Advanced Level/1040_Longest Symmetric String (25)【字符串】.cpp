#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 2021

int main(){
    string s;
    getline(cin,s);
    
    string temp="^"+s+"#$;
    int len=s.length();
    for(int i=0;i<len;i++){
        temp=temp+'#'+s[i];
    }
    temp+="#$";
    s=temp;
    
    len=s.length();
    int P[len];
    int C=0,mx=0;
    for(int i=1;i<len-1;i++){
        int j=2*C-i;
        if(i<mx) P[i]=min(P[j],mx-i);
        else P[i]=0;
        while(s[i+1+P[i]]==s[i-1-P[i]]) P[i]++;
        if(i+P[i]>mx){
            mx=i+P[i];
            C=i;
        }
    }
    
    int maxlen=0;
    for(int i=1;i<len-1;i++){
        maxlen=max(P[i],maxlen);
    }
    cout<<maxlen;
}
