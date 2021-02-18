#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;

int main(){
    int m,n,i,j;
    int num,u,v;
    unordered_set<int> vis;
    vector<int> pre;
    cin>>m>>n;
    pre.resize(n);
    
    for(i=0;i<n;i++){
        cin>>pre[i];
        vis.insert(pre[i]);
    }
    while(m--){
        cin>>u>>v;
        if(vis.find(u)==vis.end() && vis.find(v)==vis.end()) cout<<"ERROR: "<<u<<" and "<<v<<" are not found."<<endl;
        else if(vis.find(u)==vis.end()) cout<<"ERROR: "<<u<<" is not found."<<endl;
        else if(vis.find(v)==vis.end()) cout<<"ERROR: "<<v<<" is not found."<<endl;
        else{
            for(i=0;i<n;i++){
                if( (pre[i]<u&&pre[i]>v) || (pre[i]>u&&pre[i]<v) || pre[i]==u || pre[i]==v ) break;
            }
            if(pre[i]==u) cout<<u<<" is an ancestor of "<<v<<"."<<endl;
            else if(pre[i]==v) cout<<v<<" is an ancestor of "<<u<<"."<<endl;
            else cout<<"LCA of "<<u<<" and "<<v<<" is "<<pre[i]<<"."<<endl;
        }
    }
}
