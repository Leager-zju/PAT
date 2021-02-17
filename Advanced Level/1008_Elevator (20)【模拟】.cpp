#include<cstdio>

int main(){
    int n,i,nowfloor=0,nextfloor=0;
    int maxtime=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&nextfloor);
        if(nextfloor>nowfloor) maxtime+=6*(nextfloor-nowfloor);
        else if(nextfloor<nowfloor) maxtime+=4*(nowfloor-nextfloor);
        nowfloor=nextfloor;
    }
    maxtime+=5*n;
    printf("%d",maxtime);
}
