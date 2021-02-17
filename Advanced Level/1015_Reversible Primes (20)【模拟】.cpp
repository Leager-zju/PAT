#include<cstdio>

bool isprime(int n){
    if(n==1 || n==0) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

int change(int n,int radix){
    int ans=0;  
    while(n){
        ans=ans*radix+n%radix;
        n/=radix;
    }
    return ans;
}

int main(){
    int n,radix,num;
    while(1){
        scanf("%d",&n);
        if(n<0) break;
        scanf("%d",&radix);
        num=change(n,radix);
        if(isprime(n) && isprime(num)) printf("Yes\n");
        else printf("No\n");
    }
}
