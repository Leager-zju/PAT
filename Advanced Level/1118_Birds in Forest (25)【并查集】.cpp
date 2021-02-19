#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 10010

int father[maxn];
int findfather(int x){
    int a=x;
    while(x!=father[x]){
        x=father[x];
    }
    while(a!=father[a]){
        int temp=a;
        a=father[a];
        father[temp]=x;
    }
    return x;
}
void merge(int x,int y){
    int a=findfather(x);
    int b=findfather(y);
    if(a!=b) father[b]=a;
}

int main(){
    int n,q,k;
    int i,j,x,y,maxtag=0,count=0;
    bool flag[maxn]={false};
    
    scanf("%d",&n);
    for(i=1;i<maxn;i++){
        father[i]=i;
    }
    for(i=0;i<n;i++){
        scanf("%d",&k);
        if(k!=0){
            scanf("%d",&x);
            maxtag=max(maxtag,x);
        }
        for(j=1;j<k;j++){
            scanf("%d",&y);
            merge(x,y);
            maxtag=max(maxtag,y);
        }
    }
    for(i=1;i<=maxtag;i++){
        x=findfather(i);
        if(!flag[x]){
            flag[x]=true;
            count++;
        }
    }
    printf("%d %d\n",count,maxtag);
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&x,&y);
        if(findfather(x)!=findfather(y)) printf("No\n");
        else printf("Yes\n");
    }
}
