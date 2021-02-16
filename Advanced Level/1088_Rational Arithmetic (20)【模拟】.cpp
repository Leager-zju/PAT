#include<cstdio>
#include<string>
#include<cmath>
using namespace std;

struct info{
    long int integer,numerator,denominator;
}a,b,sum,difference,product,quotient;

long int gcd(long int n,long int m){
    if(m==0) return abs(n);
    else return gcd(m,n%m);
}
long int lcm(long int n,long int m){
    return abs(n*m)/gcd(n,m);
}

info simplify(info a){
    long int temp=gcd(a.denominator,a.numerator);
    a.denominator/=temp;
    a.numerator/=temp;
    a.integer=a.numerator/a.denominator;
    return a;
}
string transform(info num){
    string ans;
    int flag=0;
    if(num.integer==0 && num.numerator==0) return "0";
    if(num.integer<0 || num.numerator<0) flag=1;
    if(num.integer!=0) ans=to_string(num.integer)+" ";
    if(num.numerator%num.denominator!=0){
        if(num.integer!=0) ans+=to_string(abs(num.numerator%num.denominator))+"/"+to_string(abs(num.denominator));
        else ans+=to_string(num.numerator%num.denominator)+"/"+to_string(num.denominator);
    }
    else ans.erase(ans.end()-1);
    if(flag) ans="("+ans+")";
    return ans;
}
int main(){
    string A,B,s,d,p,q;
    long int temp;
    scanf("%ld/%ld %ld/%ld",&a.numerator,&a.denominator,&b.numerator,&b.denominator);
    a=simplify(a);
    b=simplify(b);
    A=transform(a);
    B=transform(b);
    // sum
    temp=lcm(a.denominator,b.denominator);
    sum.denominator=temp;
    sum.numerator=temp*a.numerator/a.denominator+temp*b.numerator/b.denominator;
    sum=simplify(sum);
    s=transform(sum);
    printf("%s + %s = %s\n",A.c_str(),B.c_str(),s.c_str());
    // difference
    temp=lcm(a.denominator,b.denominator);
    difference.denominator=temp;
    difference.numerator=temp*a.numerator/a.denominator-temp*b.numerator/b.denominator;
    difference=simplify(difference);
    d=transform(difference);
    printf("%s - %s = %s\n",A.c_str(),B.c_str(),d.c_str());
    // product
    product.denominator=a.denominator*b.denominator;
    product.numerator=a.numerator*b.numerator;
    product=simplify(product);
    p=transform(product);
    printf("%s * %s = %s\n",A.c_str(),B.c_str(),p.c_str());
    // quotient
    if(B=="0") q="Inf";
    else{
        quotient.denominator=a.denominator*b.numerator;
        quotient.numerator=a.numerator*b.denominator;
        if(quotient.denominator<0){
            quotient.numerator=-quotient.numerator;
            quotient.denominator=-quotient.denominator;
        }
        quotient=simplify(quotient);
        q=transform(quotient);
    }
    printf("%s / %s = %s\n",A.c_str(),B.c_str(),q.c_str());
}
