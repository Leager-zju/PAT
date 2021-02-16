#include<cstdio>
#include<math.h>

bool isprime(int n){
    if(n==1||n==0) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    int maxsize,n,num;
    scanf("%d %d",&maxsize,&n);
    while(!isprime(maxsize)){
        maxsize++;
    }
    int hash[maxsize]={0};
    int pos[n];
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        int k,epos;
        for(k=0;k<maxsize;k++){
            epos=(num+k*k)%maxsize;
            if(hash[epos]==0){
                hash[epos]=num;
                pos[i]=epos;
                break;
            }
        }
        if(k==maxsize) pos[i]=-1;
    }
    for(int i=0;i<n;i++){
        if(i!=0) printf(" ");
        if(pos[i]==-1) printf("-");
        else printf("%d",pos[i]);
    }
}
