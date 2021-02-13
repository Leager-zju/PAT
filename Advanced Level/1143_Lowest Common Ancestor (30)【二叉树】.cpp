#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

int main(){
    int m,n,i,j;
    int num,u,v;
    cin>>m>>n;
    
    vector<int> pre(n);
    unordered_map<int,bool> have;   // 树中是否有某个结点
    
    for(i=0;i<n;i++){
        cin>>pre[i];
        have[pre[i]]=true;
    }
    while(m--){
        cin>>u>>v;
        if(have.find(u)==have.end() && have.find(v)==have.end()) cout<<"ERROR: "<<u<<" and "<<v<<" are not found."<<endl;
        else if(have.find(u)==have.end()) cout<<"ERROR: "<<u<<" is not found."<<endl;
        else if(have.find(v)==have.end()) cout<<"ERROR: "<<v<<" is not found."<<endl;
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
