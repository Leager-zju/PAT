#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

bool isPalindromic(string s){
    string temp=s;
    reverse(temp.begin(),temp.end());
    return (s==temp);
}
string add(string a){
    int flag=0,len=a.length();
    int nowdigit;
    string sum;
    char c;
    for(int i=len-1;i>=0;i--){
        nowdigit=a[i]-'0'+a[len-i-1]-'0'+flag;
        if(nowdigit>=10){
            nowdigit-=10;
            flag=1;
        }
        else flag=0;
        c=nowdigit+'0';
        sum=c+sum;
    }
    if(flag) sum="1"+sum;
    return sum;
}

int main(){
    string num;
    int K,cnt=0;
    cin>>num>>K;
    while(cnt!=K && !isPalindromic(num)){
        num=add(num);
        cnt++;
    }
    cout<<num<<endl<<cnt;
}
