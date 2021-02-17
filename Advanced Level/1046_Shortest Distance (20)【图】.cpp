#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n,m,u,v,C=0;
    cin>>n;
    int dis[n+1];
    dis[0]=0;
    for(int i=1;i<=n;i++){
        cin>>dis[i];
        C+=dis[i];
        dis[i]+=dis[i-1];
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        int len=u>v?dis[u-1]-dis[v-1]:dis[v-1]-dis[u-1];
        if(2*len>C) cout<<C-len<<endl;
        else cout<<len<<endl;
    }
}
