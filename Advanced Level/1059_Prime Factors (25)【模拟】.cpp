#include<iostream>
#include<map>
#include<math.h>
using namespace std;
#define maxn 10000008

long int num,n,pnum=0;
map<long int,int> m;
map<long int,int>::iterator it;
bool prime[maxn]={false};
long int p[maxn];

void initial(long int bound){
    for(int i=2;i<=sqrt(bound);i++){
        if(prime[i]==false){
            for(int j=2*i;j<=sqrt(bound);j+=i) prime[j]=true;
            p[pnum++]=i;
        }
    }
}

int main(){
    cin>>num;
    n=num;
    int flag=1,i=0;
    initial(num);
    
    while(i<=pnum-1&&num!=1){
        while(num%p[i]==0){
            m[p[i]]++;
            num/=p[i];
        }
        i++;
    }
    cout<<n<<"=";
    for(it=m.begin();it!=m.end();it++){
        if(flag){
            flag=0;
            cout<<it->first;
        }
        else cout<<"*"<<it->first;
        if(it->second!=1) cout<<"^"<<it->second;
    }
    if(flag) cout<<n;
}
