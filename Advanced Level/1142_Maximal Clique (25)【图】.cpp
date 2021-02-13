#include<cstdio>
#include<vector>
using namespace std;

int main(){
    int Graph[202][202]={0};
    int n,m,k,i,j;
    int v1,v2;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d",&v1,&v2);
        Graph[v1][v2]=1;
        Graph[v2][v1]=1;
    }
    scanf("%d",&m);
    while(m--){
        int flag=0;
        scanf("%d",&k);
        
        vector<int> temp;
        bool vis[n+1]={false};

        for(i=0;i<k;i++){
            scanf("%d",&v1);
            if(flag) continue;
            for(j=0;j<temp.size();j++){
                if(Graph[v1][temp[j]]==0) flag=1;
            }
            temp.push_back(v1);
            vis[v1]=true;
        }
        
        if(flag) printf("Not a Clique\n");
        else{
            int ans=1;
            for(i=1;i<=n;i++){
                if(vis[i]) continue;
                for(j=0;j<temp.size();j++){
                    if(Graph[i][temp[j]]==0) break;
                }
                if(j==temp.size()){
                    ans=0;
                    printf("Not Maximal\n");
                    break;
                }
            }
            if(ans) printf("Yes\n");
        }
    }
}
