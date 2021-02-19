#include<cstdio>
#include<algorithm>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    int n,i;
    int mile[100010];
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&mile[i]);
    }
    sort(mile+1,mile+n+1,cmp);
    for(i=1;i<=n;i++){
        if(mile[i]<=i) break;
    }
    printf("%d",i-1);
}
