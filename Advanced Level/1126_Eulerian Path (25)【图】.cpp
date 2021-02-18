#include<cstdio>
#include<vector>
using namespace std;

vector<int> graph[520];
bool visited[520]={false};
int degree[520]={0};

void DFS(int start){
    visited[start]=true;
    for(int i=0;i<graph[start].size();i++){
        if(!visited[graph[start][i]]) DFS(graph[start][i]);
    }
}

int main(){
    int v,e,i,start,end;
    int oddcount=0;
    scanf("%d %d",&v,&e);
    while(e--){
        scanf("%d %d",&start,&end);
        graph[start].push_back(end);
        graph[end].push_back(start);
        degree[start]++;
        degree[end]++;
    }
    for(i=1;i<=v;i++){
        if(i!=1) printf(" ");
        printf("%d",degree[i]);
        if(degree[i]%2) oddcount++;
    }
    printf("\n");
    
    DFS(1);
    for(i=1;i<=v;i++){
        if(!visited[i]) break;
    }
    if(i==v+1 && oddcount==0) printf("Eulerian");
    else if(i==v+1 && oddcount==2) printf("Semi-Eulerian");
    else printf("Non-Eulerian");
}
