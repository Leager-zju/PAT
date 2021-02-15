#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    int n,i,j,x,y,p=0;
    scanf("%d",&n);
    int list[n];
    
    for(i=0;i<n;i++){
        scanf("%d",&list[i]);
    }
    for(y=(int)sqrt(n);y>=1;y--){
        if(n%y==0){
           x=n/y;
           break; 
        }
    }
    int matrix[x][y];
    int x1,x2,y1,y2;
    x1=0,x2=x-1,y1=0,y2=y-1;
    sort(list,list+n,cmp);
    if(n==1) printf("%d",list[0]);
    else {
        while(p<n){
            for(i=y1;i<=y2&&p<n;i++){
                matrix[x1][i]=list[p++];
            }
            for(j=x1+1;j<=x2&&p<n;j++){
                matrix[j][y2]=list[p++];
            }
            for(i=y2-1;i>=y1&&p<n;i--){
                matrix[x2][i]=list[p++];
            }
            for(j=x2-1;j>=x1+1&&p<n;j--){
                matrix[j][y1]=list[p++];
            }
            x1++,x2--;
            y1++,y2--;
        }

        // output
        for(i=0;i<x;i++){
            for(j=0;j<y;j++){
                if(j!=0) printf(" ");
                printf("%d",matrix[i][j]);
            }
            printf("\n");
        }
    }
}
