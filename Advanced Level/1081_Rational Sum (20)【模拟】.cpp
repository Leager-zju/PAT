#include<cstdio>

struct info{
    long int numerator,denominator;
};

long int gcd(long int n,long int m){
    if(m==0) return n;
    else return gcd(m,n%m);
}

long int lcm(long int n,long int m){
    return n*m/gcd(n,m);
}

int main(){
    long int n,i,integer=0;
    scanf("%ld",&n);
    info list[n],ans,temp;
    for(i=0;i<n;i++){
        scanf("%ld/%ld",&list[i].numerator,&list[i].denominator);
    }
    ans=list[0];
    for(i=1;i<n;i++){
        temp=list[i];
        long int newdenominator=lcm(ans.denominator,temp.denominator);
        
        ans.numerator*=(newdenominator/ans.denominator);
        ans.denominator=newdenominator;
        temp.numerator*=(newdenominator/temp.denominator);
        ans.numerator+=temp.numerator;
        
        long int x=gcd(ans.numerator,ans.denominator);
        if(x!=0){
            ans.numerator/=x;
            ans.denominator/=x;            
        }
    }
    if(ans.numerator>=ans.denominator){
        integer=ans.numerator/ans.denominator;
        ans.numerator%=ans.denominator;
    }
    if(integer==0){
        if(ans.numerator!=0) printf("%ld/%ld",ans.numerator,ans.denominator);
        else printf("0");
    }
    else{
        printf("%ld",integer);
        if(ans.numerator!=0) printf(" %ld/%ld",ans.numerator,ans.denominator);
    }
}
