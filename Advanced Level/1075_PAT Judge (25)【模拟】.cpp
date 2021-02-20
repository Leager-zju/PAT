#include<cstdio>
#include<algorithm>
using namespace std;

struct info{
    int id,total=0,perfect=0,get[6];
    bool flag=false;
};

bool cmp(info &a,info &b){
    if(a.flag!=b.flag) return a.flag>b.flag;
    else if(a.total!=b.total) return a.total>b.total;
    else if(a.perfect!=b.perfect) return a.perfect>b.perfect;
    else return a.id<b.id;
}

int main(){
    int n,k,m,i,rank=1;
    int u_id,p_id,get_score;
    scanf("%d %d %d",&n,&k,&m);
    
    int score[k+1];
    info list[n+1];
    for(i=1;i<=k;i++){
        scanf("%d",&score[i]);
    }
    for(i=1;i<=n;i++){
        list[i].id=i;
        fill(list[i].get+1,list[i].get+k+1,-1);
    }
    for(i=0;i<m;i++){
        scanf("%d %d %d",&u_id,&p_id,&get_score);
        if(get_score==-1) get_score=0;
        else list[u_id].flag=true;
        if(get_score==score[p_id] && list[u_id].get[p_id]!=score[p_id]) list[u_id].perfect++;
        if(list[u_id].get[p_id]==-1){
            list[u_id].get[p_id]=get_score;
            list[u_id].total+=get_score;
        }
        else if(get_score>list[u_id].get[p_id]){
            list[u_id].total=list[u_id].total-list[u_id].get[p_id]+get_score;
            list[u_id].get[p_id]=get_score;
        }
    }

    sort(list+1,list+n+1,cmp);
    for(i=1;i<=n;i++){
        if(list[i].flag==false) break;
        if(i>1 && list[i].total!=list[i-1].total) rank=i;
        printf("%d %05d %d",rank,list[i].id,list[i].total);
        for(int j=1;j<=k;j++){
            if(list[i].get[j]==-1) printf(" -");
            else printf(" %d",list[i].get[j]);
        }
        printf("\n");
    }
}
