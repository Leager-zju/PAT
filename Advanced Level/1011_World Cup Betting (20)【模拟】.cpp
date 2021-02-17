#include<cstdio>

struct info{
    double result[3];
    int flag;
}game[3];

int main(){
    for(int i=0;i<3;i++){
        scanf("%lf %lf %lf",&game[i].result[0],&game[i].result[1],&game[i].result[2]);
        if(game[i].result[0]>game[i].result[1] && game[i].result[0]>game[i].result[2]) game[i].flag=0;
        else if(game[i].result[1]>game[i].result[0] && game[i].result[1]>game[i].result[2]) game[i].flag=1;
        else if(game[i].result[2]>game[i].result[0] && game[i].result[2]>game[i].result[1]) game[i].flag=2;
    }
    char choice[3]={'W','T','L'};
    double profit=1.0;
    for(int i=0;i<3;i++){
        printf("%c ",choice[game[i].flag]);
        profit*=game[i].result[game[i].flag];
    }
    printf("%.2f",(profit*0.65-1)*2.0);
}
