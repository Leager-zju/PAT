#include<iostream>
#include<map>
using namespace std;
#define maxn 10000008

long int num,n,pnum=0,p[maxn];
bool prime[maxn]={false};
map<long int,int> m;

void initial(long int bound){
    for(int i=2;i*i<=bound;i++){
        if(prime[i]==false){
            for(int j=2*i;j*j<=bound;j+=i) prime[j]=true;
            p[pnum++]=i;
        }
    }
}

int main(){
    int flag=1,i=0;
    cin>>num;
    n=num;
    initial(num);
    while(i<pnum && num!=1){
        while(num%p[i]==0){
            m[p[i]]++;
            num/=p[i];
        }
        i++;
    }
    cout<<n<<"=";
    for(auto it=m.begin();it!=m.end();it++){
        if(flag){
            flag=0;
            cout<<it->first;
        }
        else cout<<"*"<<it->first;
        if(it->second!=1) cout<<"^"<<it->second;
    }
    if(flag) cout<<n;
}
