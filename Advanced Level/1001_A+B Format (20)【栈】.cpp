#include<stack>
#include<cstdio>
using namespace std;

int main(){
    int a,b,sum;
    int flag=1;
    stack<int> s;
    
    scanf("%d %d",&a,&b);
    sum=a+b;
    if(sum<0){
        flag=-1;
        sum=-sum;
    }
    else if(sum==0){
        printf("%d",sum);
        return 0;
    }
    
    while(sum){
        s.push(sum%1000);
        sum/=1000;
    }
    sum=s.top();
    s.pop();
    if(flag==-1) printf("-");
    printf("%d",sum);
    while(!s.empty()){
        sum=s.top();
        printf(",%03d",sum);
        s.pop();
    }
}
