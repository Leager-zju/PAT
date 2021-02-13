#include<unordered_map>
#include<iostream>
using namespace std;

int main(){
    int n,num,i,maxnum=-1;
    unordered_map<int,bool> mp;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>num;
        if(num>0){
            mp[num]=true;
            maxnum=max(maxnum,num);
        }
    }
    for(i=1;i<=maxnum;i++){
        if(mp[i]!=true) break;
    }
    cout<<i;
}
