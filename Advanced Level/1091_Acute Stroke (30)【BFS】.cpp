#include<cstdio>
#include<queue>
using namespace std;

bool visit[1300][130][70]={false};
int stoke[1300][130][70];
int x[6]={0,0,0,0,1,-1};
int y[6]={0,0,1,-1,0,0};
int z[6]={1,-1,0,0,0,0};
int m,n,l,t;

struct info{
    int a,b,c;
}temp,top;

int BFS(int i,int j,int k){
    int tempcount=0,p;
    temp.a=i;
    temp.b=j;
    temp.c=k;
    queue<info> Q;
    Q.push(temp);
    visit[i][j][k]=true;
    while(!Q.empty()){
        top=Q.front();
        Q.pop();
        tempcount++;
        for(p=0;p<6;p++){
            temp.a=top.a+x[p];
            temp.b=top.b+y[p];
            temp.c=top.c+z[p];
            if(temp.a>=0 && temp.a<m && temp.b>=0 && temp.b<n && temp.c>=0 && temp.c<l && !visit[temp.a][temp.b][temp.c] && stoke[temp.a][temp.b][temp.c]==1){
                Q.push(temp);
                visit[temp.a][temp.b][temp.c]=true;
            }
        }
    }
    if(tempcount>=t) return tempcount;
    else return 0;
}

int main(){
    int i,j,k,count=0;
    scanf("%d %d %d %d",&m,&n,&l,&t);
    for(k=0;k<l;k++){
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                scanf("%d",&stoke[i][j][k]);
            }
        }
    }
    
    for(k=0;k<l;k++){
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(!visit[i][j][k] && stoke[i][j][k]==1) count+=BFS(i,j,k);
            }
        }
    }
    printf("%d",count);
    return 0;
}
