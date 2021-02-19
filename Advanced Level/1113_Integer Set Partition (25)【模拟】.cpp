#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int n,i;
    long int num[100010],sum1=0,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%ld",&num[i]);
        sum+=num[i];
    }
    sort(num,num+n);
    for(i=0;i<n/2;i++){
        sum1+=num[i];
    }
    printf("%d %ld",n%2,sum-2*sum1);
}
