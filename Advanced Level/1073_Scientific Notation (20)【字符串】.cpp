// 我将字符串分为三部分：整数部分、小数部分、指数部分
// 先将指数部分变为int型，根据正负来判断小数点左移还是右移
// 左移补零，右移位数不够补零
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
