#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

bool exist[10]={false},newexist[10]={false};

string getdouble(string s){
    string news;
    int flag=0,len=s.length(),nowdigit,i;
    char c;
    for(i=len-1;i>=0;i--){
        nowdigit=(s[i]-'0')*2+flag;
        if(nowdigit>=10){
            nowdigit-=10;
            flag=1;
        }
        else flag=0;
        c=nowdigit+'0';
        news=c+news;
    }
    if(flag) news="1"+news;
    return news;
}

int main(){
    string num,newnum;
    int i;
    cin>>num;
    newnum=getdouble(num);
    
    for(i=0;i<num.length();i++){
        exist[num[i]-'0']=true;
    }
    for(i=0;i<newnum.length();i++){
        newexist[newnum[i]-'0']=true;
    }
    for(i=0;i<10;i++){
        if(exist[i]!=newexist[i]) break;
    }
    if(i==10) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    cout<<newnum;
}
