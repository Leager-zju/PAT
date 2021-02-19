#include<cstdio>
#include<string.h>

int main(){
    int n,i,j,count=0;
    char a[100],b[100];
    double sum=0.0,num;
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",a);
        sscanf(a,"%lf",&num);
        sprintf(b,"%.2f",num);
        for(j=0;j<strlen(a);j++){
            if(a[j]!=b[j]) break;
        }
        if(j==strlen(a) && num>=-1000 && num<=1000){
            sum+=num;
            count++;
        }
        else printf("ERROR: %s is not a legal number\n",a);
    } 
    if(count==0) printf("The average of 0 numbers is Undefined\n");
    else if(count==1) printf("The average of 1 number is %.2lf\n",sum/count);
    else printf("The average of %d numbers is %.2lf\n",count,sum/count);
}
