#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m,l,i,j;
    int a,num=0;
    cin>>n;
    cin>>m;
    vector<int> favor(n+1,0);
    for(i=1;i<=m;i++){
        cin>>a;
        favor[a]=i;
    }
    cin>>l;
    vector<int> s(l),dp(l);
    for(i=0;i<l;i++){
        cin>>a;
        if(favor[a]>0) s[num++]=a;
        dp[i]=1;
    }
    int maxlen=0;
    for(i=0;i<num;i++){
        for(j=0;j<i;j++){
            if(favor[s[j]]<=favor[s[i]]) dp[i]=max(dp[j]+1,dp[i]);
        }
        maxlen=max(dp[i],maxlen);
    }
    cout<<maxlen;
    return 0;
}
