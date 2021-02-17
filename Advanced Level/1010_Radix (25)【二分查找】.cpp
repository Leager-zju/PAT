#include<cstdio>
#include<string>
using namespace std;

long long int str_num(string s,long long int radix){
    long long int num=0;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])) num=num*radix+s[i]-'0';
        else if(isalpha(s[i])) num=num*radix+s[i]-'a'+10;
        else break;
    }
    return num;
}

int findMaxRadix(string s){
    int MaxRadix=2;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])) MaxRadix=max(MaxRadix,s[i]-'0'+1);
        else if(isalpha(s[i])) MaxRadix=max(MaxRadix,s[i]-'a'+11);
        else break;
    }
    return MaxRadix;
}

void match(string s1,string s2,long long int radix){
    long long int num1=str_num(s1,radix),num2;
    long long int left=findMaxRadix(s2),right=num1+1,mid;
    while(left<right){
        mid=(left+right)/2;
        num2=str_num(s2,mid);
        if(num1==num2){
            printf("%d",mid);
            return;
        }
        else if(num1<num2||num2<0) right=mid-1;
        else left=mid+1;
    }
    if(num1==str_num(s2,left)) printf("%d",left);
    else printf("Impossible");
}

int main(){
    string s1,s2;
    int tag,radix;
    s1.resize(10),s2.resize(10);
    scanf("%s %s %d %d",&s1[0],&s2[0],&tag,&radix);
    if(tag==1) match(s1,s2,radix);
    else if(tag==2) match(s2,s1,radix);
}
