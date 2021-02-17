#include<set>
#include<unordered_map>
#include<cstdio>
using namespace std;

unordered_map<string,set<int>> list;

int main(){
    int k,n,n_i,id,i,j;
    char name[4];
    scanf("%d %d",&k,&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&id,&n_i);
        for(j=0;j<n_i;j++){
            scanf("%s",name);
            list[name].insert(id);
        }
    }
    
    while(k--){
        scanf("%s",name);
        printf("%s %d",name,(int)list[name].size());
        for(auto it=list[name].begin();it!=list[name].end();it++){
            printf(" %d",*it);
        }
        printf("\n");
    }
}
