#include<cstdio>
#include<algorithm>
using namespace std;

struct info{
    double num,price;
};

bool cmp(info &a,info &b){
    return a.price>b.price;
}

int main(){
    int k,i;
    double req,profit;
    scanf("%d %lf",&k,&req);
    info mk[k];
    for(i=0;i<k;i++){
        scanf("%lf",&mk[i].num);
    }
    for(i=0;i<k;i++){
        scanf("%lf",&mk[i].price);
        mk[i].price/=mk[i].num;
    }
    sort(mk,mk+k,cmp);
    i=0;
    while(req && i<k){
        if(req>mk[i].num){
            profit+=mk[i].num*mk[i].price;
            req-=mk[i].num;
        }
        else{
            profit+=req*mk[i].price;
            req=0;
        }
        i++;
    }
    printf("%.2f",profit);
}
