#include<cstdio>
#include<vector>
using namespace std;

int main(){
    int n,m,u,v,i,k;
    scanf("%d %d",&n,&m);
    vector<int> check[100010];
    while(n--){
        scanf("%d %d",&u,&v);
        check[u].push_back(v);
        check[v].push_back(u);
    }
    
    while(m--){
        scanf("%d",&k);
        int flag=0;
        bool container[100010]={false};
        while(k--){
            scanf("%d",&u);
            if(flag==1) continue;
            if(container[u]) flag=1;
            for(i=0;i<check[u].size();i++){
                v=check[u][i];
                container[v]=true;
            }
        }
        if(flag) printf("No\n");
        else printf("Yes\n");
    }
}
