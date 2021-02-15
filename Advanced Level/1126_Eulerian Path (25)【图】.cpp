#include<iostream>
using namespace std;

int graph[520][520]={0};
bool visited[520]={false};

void DFS(int start,int v){
    visited[start]=true;
    for(int i=1;i<=v;i++){
        if(graph[start][i]==1 && !visited[i]){
            DFS(i,v);
        }
    }
}

int main(){
    int v,e,i,start,end;
    int oddcount=0;
    int flag=0;
    cin>>v>>e;
    int degree[520]={0};
    while(e--){
        cin>>start>>end;
        graph[start][end]=graph[end][start]=1;
        degree[start]++;
        degree[end]++;
    }
    for(i=1;i<=v;i++){
        if(i!=1) cout<<" ";
        cout<<degree[i];
        if(degree[i]%2) oddcount++;
    }
    DFS(1,v);
    for(i=1;i<=v;i++){
        if(visited[i]==false) break;
    }
    if(i==v+1) flag=1;
    cout<<endl;
    if(flag==1 && oddcount==0) cout<<"Eulerian";
    else if(flag==1 && oddcount==2) cout<<"Semi-Eulerian";
    else cout<<"Non-Eulerian";
}
