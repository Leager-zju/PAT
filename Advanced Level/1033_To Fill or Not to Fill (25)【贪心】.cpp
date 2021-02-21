// 贪心，考虑局部最优解

#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn tank*avrdis

struct info{
    double price,distance;
};

vector<info> stn;

bool cmp(info &a,info &b){
    if(a.distance!=b.distance) return a.distance<b.distance;
    else return a.price<b.price;
}

int main(){
    int n,i;
    double minprice=0.0,tank,dis,avrdis;
    scanf("%lf %lf %lf %d",&tank,&dis,&avrdis,&n);
    
    stn.resize(n+1);
    for(i=0;i<n;i++){
        scanf("%lf %lf",&stn[i].price,&stn[i].distance);
    }
    stn[n].price=0;
    stn[n].distance=dis;
    sort(stn.begin(),stn.end(),cmp);
    if(stn[0].distance>0){
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    for(i=0;i<n;i++){
        if(stn[i].distance==dis) break;
        if(stn[i+1].distance-stn[i].distance>maxn){
            printf("The maximum travel distance = %.2f",stn[i].distance+1.0*maxn);
            return 0;
        }
    }

    int now,next,remain=0;
    for(now=0;now<n;now++){
        next=now+1;
        if(now!=0) remain-=(stn[now].distance-stn[now-1].distance);
        if(remain>=stn[next].distance-stn[now].distance) continue;
        if(stn[now].distance==dis) break;

        for(i=next;i<=n;i++){
            if(stn[i].price<=stn[now].price){
                if(stn[i].distance-stn[now].distance>maxn){
                    minprice+=stn[now].price*(maxn-remain);
                    remain=maxn;
                }
                else{
                    minprice+=(stn[i].distance-stn[now].distance-remain)*stn[now].price;
                    remain=stn[i].distance-stn[now].distance;
                }
                break;
            }
        }
    }
    printf("%.2f",minprice/(1.0*avrdis));
}
