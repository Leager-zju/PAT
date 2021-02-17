#include<cstdio>
#include<vector>
using namespace std;
#define maxn 1002

int father[maxn];
int Graph[maxn][maxn]={0};

int findfather(int x){
    int temp,a=x;
    while(father[x]!=x){
        x=father[x];
    }
    while(a!=x){
        temp=a;
        a=father[a];
        father[temp]=x;
    }
    return x;
}

void Union(int x,int y){
    int a=findfather(x),b=findfather(y);
    if(a!=b) father[b]=a;
}

void search(int x,int n){
    int i,num=0;
    bool dif_father[n+1]={false};
    for(i=1;i<=n;i++){
        father[i]=i;
    }
    for(i=1;i<=n;i++){
        if(i==x) continue;
        for(int j=i+1;j<=n;j++){
            if(j!=x && Graph[i][j]==1) Union(i,j);
        }
    }
    for(i=1;i<=n;i++){
        if(i!=x && !dif_father[findfather(i)]){
            dif_father[findfather(i)]=true;
            num++;
        }
    }
    printf("%d\n",num-1);
}

int main(){
    int n,NumOfWays,k,i;
    int start,end,Concern;
    
    scanf("%d %d %d",&n,&NumOfWays,&k);
    for(i=0;i<NumOfWays;i++){
        scanf("%d %d",&start,&end);
        Graph[start][end]=Graph[end][start]=1;
    }
    for(i=0;i<k;i++){
        scanf("%d",&Concern);
        search(Concern,n);
    }
}
