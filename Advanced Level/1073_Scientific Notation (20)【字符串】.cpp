#include<string>
#include<iostream>
using namespace std;

string transform(string s){
    string ans,e,integer,demical;
    int i,epos,exp=0,len=s.length();
    for(i=len;i>=0;i--){
        if(s[i]=='E') break;
    }
    epos=i;
    integer=s.substr(1,1);
    demical=s.substr(3,epos-3);
    e=s.substr(epos+1,len-epos-1);
    for(i=1;i<e.length();i++){
        exp=exp*10+(e[i]-'0');
    }
    if(e[0]=='-'){
        ans+="0.";
        for(i=exp;i>1;i--){
            ans+="0";
        }
        ans+=integer+demical;
    }
    else{
        ans=integer+demical;
        if(ans.length()<=exp+1){
            for(i=ans.length();i<=exp;i++){
                ans+="0";
            }
        }
        else ans.insert(exp+1,".");
    }
    if(s[0]=='-') ans="-"+ans;
    return ans;
}

int main(){
    string input;
    cin>>input;
    cout<<transform(input);
}
