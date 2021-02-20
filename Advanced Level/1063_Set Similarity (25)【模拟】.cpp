#include<cstdio>
#include<unordered_set>
using namespace std;

void compare(unordered_set<int> a,unordered_set<int> b){
    double nc=0,nt=(double)b.size(),similar;
    int num;
    for(auto it:a){
        if(b.count(it)!=0) nc++;
        else nt++;
    }
    similar=nc/nt*100.0;
    printf("%.1f%%\n",similar);
    return ;
}

int main(){
    int n,m,num;
    int i,j;
    scanf("%d",&n);
    
    unordered_set<int> s[n+1];
    for(i=1;i<=n;i++){
        scanf("%d",&m);
        for(j=0;j<m;j++){
            scanf("%d",&num);
            s[i].insert(num);
        }
    }
    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%d %d",&n,&m);
        compare(s[n],s[m]);
    }
}
