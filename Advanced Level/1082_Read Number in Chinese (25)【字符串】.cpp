#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

string digit[5]={" Shi"," Bai"," Qian"," Wan"," Yi"};
string number[10]={" ling"," yi"," er"," san"," si"," wu"," liu"," qi"," ba"," jiu"};

string transform(string n){
    string ans;
    int len=n.length();
    reverse(n.begin(),n.end());
    
    if(n[0]!='0') ans=number[n[0]-'0']+ans;
    for(int i=1;i<len;i++){
        if(n[i]!='0') ans=digit[i-1]+ans;
        if(!(n[i]=='0' && n[i-1]=='0')) ans=number[n[i]-'0']+ans;
    }
    return ans;
}

int main(){
    string num,ans;
    int flag=0,j=3;
    cin>>num;
    if(num=="0"){
        cout<<"ling";
        return 0;
    }
    if(num[0]=='-'){
        flag=1;
        num.erase(num.begin());
    }
    for(int i=num.length()-1;i>=0;i-=4){
        if(i>=4) ans=digit[j++]+transform(num.substr(i-3,4))+ans;
        else ans=transform(num.substr(0,i+1))+ans;
    }
    ans.erase(ans.begin());
    if(flag) ans="Fu "+ans;
    cout<<ans;
}
