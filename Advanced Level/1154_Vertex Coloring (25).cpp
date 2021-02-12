#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

vector<int> Graph[10100];

int main(){
    int n,m,k,u,v,i,j;
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>u>>v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    cin>>k;
    while(k--){
        int color[n];
        int flag=0;
        unordered_map<int,bool> vis;
        for(i=0;i<n;i++){
            cin>>color[i];
            vis[color[i]]=true;
        }
        for(i=0;i<n;i++){
            if(flag) break;
            for(j=0;j<Graph[i].size();j++){
                u=Graph[i][j];
                if(color[i]==color[u]){
                    flag=1;
                    break;
                }
            }
        }
        if(flag) cout<<"No"<<endl;
        else{
            flag=vis.size();
            cout<<flag<<"-coloring"<<endl;
        }
    }
}
