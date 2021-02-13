#include<vector>
#include<iostream>
using namespace std;

int main(){
    int n,m,q,i,j,k,u,v;
    cin>>n>>m;
    vector<int> degree(n+1,0),temp,ans;
    vector<int> next[n+1];
    for(i=0;i<m;i++){
        cin>>u>>v;
        next[u].push_back(v);
        degree[v]++;
    }
    cin>>q;
    for(i=0;i<q;i++){
        int flag=0;
        temp=degree;
        for(j=0;j<n;j++){
            cin>>u;
            if(flag) continue;
            if(temp[u]!=0) flag=1;
            else{
                for(k=0;k<next[u].size();k++){
                    temp[next[u][k]]--;
                }
            }
        }
        if(flag) ans.push_back(i);
    }
    for(i=0;i<ans.size();i++){
        if(i!=0) cout<<" ";
        cout<<ans[i];
    }
}
