#include<map>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(){
    double A[1002]={0.0},B[1002]={0.0},C[2004]={0.0};
    double coe;
    int n1,n2,count=0,exp;
    int i,j;
    
    scanf("%d",&n1);
    for(i=0;i<n1;i++){
        scanf("%d",&exp);
        scanf("%lf",&A[exp]);
    }
    scanf("%d",&n2);
    for(i=0;i<n2;i++){
        scanf("%d",&exp);
        scanf("%lf",&B[exp]);
    }
    for(i=0;i<1002;i++){
        if(A[i]==0.0) continue;
        for(j=0;j<1002;j++){
            if(B[j]==0.0) continue;
            C[i+j]+=A[i]*B[j];
        }
    }
    for(i=0;i<2004;i++){
        if(C[i]!=0.0) count++;
    }
    printf("%d",count);
    for(i=2003;i>=0;i--){
        if(C[i]!=0.0) printf(" %d %.1f",i,C[i]);
    }
}
