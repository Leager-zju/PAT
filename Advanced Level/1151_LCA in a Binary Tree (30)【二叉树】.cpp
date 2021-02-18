#include<vector>
#include<unordered_map>
#include<cstdio>
using namespace std;

unordered_map<int,int> repo;
vector<int> pre;

int main(){
    int n,m,i,j,u,v;
    scanf("%d %d",&m,&n);
    for(i=1;i<=n;i++){
        scanf("%d",&u);
        repo[u]=i;
    }
    pre.resize(n);
    for(i=0;i<n;i++){
        scanf("%d",&pre[i]);
    }
    while(m--){
        scanf("%d %d",&u,&v);
        if(repo.find(u)==repo.end() && repo.find(v)==repo.end()) printf("ERROR: %d and %d are not found.\n",u,v);
        else if(repo.find(u)==repo.end()) printf("ERROR: %d is not found.\n",u);
        else if(repo.find(v)==repo.end()) printf("ERROR: %d is not found.\n",v);
        else{
            for(j=0;j<n;j++){
                i=repo[pre[j]];
                if( (i==repo[u]) || (i==repo[v]) || (i<=repo[u]&&i>=repo[v]) || (i<=repo[v]&&i>=repo[u]) ) break;
            }
            if(i==repo[u])      printf("%d is an ancestor of %d.\n",u,v);
            else if(i==repo[v]) printf("%d is an ancestor of %d.\n",v,u);
            else                printf("LCA of %d and %d is %d.\n",u,v,pre[j]);
        }
    }
}
