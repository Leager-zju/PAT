#include<cstdio>
#include<vector>
using namespace std;

bool Graph[202][202]={false};

int main(){
    int n,m,k,i,j;
    int v1,v2;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d",&v1,&v2);
        Graph[v1][v2]=Graph[v2][v1]=true;
    }
    scanf("%d",&m);
    while(m--){
        int flag=0;
        bool vis[n+1]={false};
        vector<int> temp;
        scanf("%d",&k);
        for(i=0;i<k;i++){
            scanf("%d",&v1);
            if(flag) continue;
            for(j=0;j<temp.size();j++){
                if(!Graph[v1][temp[j]]) flag=1;
            }
            temp.push_back(v1);
            vis[v1]=true;
        }
        if(flag) printf("Not a Clique\n");
        else{
            for(i=1;i<=n;i++){
                if(vis[i]) continue;
                for(j=0;j<temp.size();j++){
                    if(!Graph[i][temp[j]]) break;
                }
                if(j==temp.size()){
                    flag=1;
                    printf("Not Maximal\n");
                    break;
                }
            }
            if(!flag) printf("Yes\n");
        }
    }
}
