#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int n,i,m;
    long int num[100010],sum1=0,sum2=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%ld",&num[i]);
    }
    sort(num,num+n);
    m=n/2;
    for(i=0;i<m;i++){
        sum1+=num[i];
    }
    for(i=m;i<n;i++){
        sum2+=num[i];
    }
    printf("%d %ld",n-2*m,sum2-sum1);
}
