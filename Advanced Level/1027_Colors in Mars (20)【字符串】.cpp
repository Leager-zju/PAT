#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

string transform(int number){
    char c;
    int digit;
    string ans;
    if(number==0) return "00";
    while(number){
        digit=number%13;
        if(digit>=10) c='A'+digit-10;
        else c=digit+'0';
        ans+=c;
        number/=13;
    }
    if(ans.length()==1) ans+='0';
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    int r,g,b;
    cin>>r>>g>>b;
    cout<<"#"<<transform(r)<<transform(g)<<transform(b);
}
