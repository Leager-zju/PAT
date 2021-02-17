#include<iostream>
#include<math.h>
#include<string>
using namespace std;

long int findones(long int n){
    if(n==0) return 0;
    else if(n<=9) return 1;
    string temp=to_string(n);
    long int digit=temp.length(),ans=0;
    long int a=(long int)pow(10,digit-2);
    long int top=n/(10*a);

    if(top==1) ans=n%(10*a)+1;
    else ans=10*a;

    ans+=top*(digit-1)*a+findones(n%(10*a));
    return ans;
}
int main(){
    long int n;
    cin>>n;
    cout<<findones(n);
}
