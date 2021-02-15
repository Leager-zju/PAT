#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

bool graph[211][211]={false};

int main(){
    int v,e,i,j,start,end,Q,k;
    scanf("%d %d",&v,&e);
    for(i=0;i<e;i++){
        scanf("%d %d",&start,&end);
        graph[start][end]=graph[end][start]=true;
    }
    scanf("%d",&Q);
    while(Q--){
        scanf("%d",&k);
        bool pass[v+1]={false};
        vector<int> path(k);
        for(i=0;i<k;i++){
            scanf("%d",&path[i]);
        }

        if(k<=v || path[0]!=path[k-1]){
            printf("NO\n");
            continue;
        }
        
        for(i=0;i<k-1;i++){
            if(pass[path[i]]==true || !graph[path[i]][path[i+1]]) break;
            else pass[path[i]]=true;
        }
        if(i==k-1) printf("YES\n");
        else printf("NO\n");
    }
}
