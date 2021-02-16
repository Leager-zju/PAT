#include<cstdio>
#include<algorithm>
using namespace std;

int reverse(int n){
    int ans=0;
    while(n){
        ans=ans*10+n%10;
        n/=10;
    }
    return ans;
}
int transform(int n){
    int a[4]={0},i=0,ans=0;
    while(n){
        a[i++]=n%10;
        n/=10;
    }
    sort(a,a+4);
    for(i=3;i>=0;i--){
        ans=ans*10+a[i];
    }
    return ans;
}

int main(){
    int n,m;
    scanf("%d",&n);
    m=reverse(n);
    while(1){
        n=transform(n);
        m=reverse(n);
        printf("%04d - %04d = %04d\n",n,m,n-m);
        n=n-m;
        if(n==0 || n==6174) break;
    }
    return 0;
}
