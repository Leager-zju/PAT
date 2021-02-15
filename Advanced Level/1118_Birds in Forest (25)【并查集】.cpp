#include<cstdio>
#include<algorithm>
using namespace std;

int father[10010];
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
    int i,j,x,y;
    int maxtag=0;

    scanf("%d",&n);

    for(i=1;i<=10000;i++){
        father[i]=i;
    }
    for(i=0;i<n;i++){
        scanf("%d",&k);
        for(j=0;j<k;j++){
            if(j==0){
                scanf("%d",&x);
                maxtag=max(maxtag,x);
            }
            else{
                scanf("%d",&y);
                merge(x,y);
                maxtag=max(maxtag,y);
            }
        }
    }
    bool flag[10010]={false};
    int count=0;
    for(i=1;i<=maxtag;i++){
        x=findfather(i);
        if(flag[x]==false){
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
