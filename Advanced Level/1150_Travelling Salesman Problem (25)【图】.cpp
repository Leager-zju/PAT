#include<iostream>
#include<vector>
using namespace std;

int main(){
    int graph[202][202]={0};
    int n,m,i,j,k,u,v,dis;
    int shortest=10e7,id=0;
    cin>>n>>m;
    
    while(m--){
        cin>>u>>v>>dis;
        graph[u][v]=graph[v][u]=dis;
    }
    cin>>m;
    for(j=1;j<=m;j++){
        int flag=0,totaldis=0,start;
        bool vis[n+1]={false};
        cin>>k>>u;
        start=u;
        for(i=1;i<k;i++){
            cin>>v;
            if(flag) continue;
            if(graph[u][v]==0){
                flag=1;
                totaldis=0;
                continue;
            }
            else totaldis+=graph[u][v];
            if(!vis[v]) vis[v]=true;
            else flag=2;
            u=v;
        }
        cout<<"Path "<<j<<": ";
        if(totaldis==0) cout<<"NA";
        else cout<<totaldis;

        if(v!=start) flag=1;
        for(i=1;i<=n;i++){
            if(!vis[i]){
                flag=1;
                break;
            }
        }
        if(flag==0)      cout<<" (TS simple cycle)"<<endl;
        else if(flag==1) cout<<" (Not a TS cycle)"<<endl;
        else if(flag==2) cout<<" (TS cycle)"<<endl;
        
        if(flag!=1 && shortest>totaldis){
            shortest=totaldis;
            id=j;
        }
    }
    cout<<"Shortest Dist("<<id<<") = "<<shortest<<endl;
}
