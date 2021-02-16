#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;

struct info{
    int floor,pro;
    vector<int> next;
    bool isdetail;
}chain[100010],temp;

int main(){
    int n,i,j,num;
    double p,r,sum=0.0;
    scanf("%d %lf %lf",&n,&p,&r);
    r=(1+0.01*r);
    
    for(i=0;i<n;i++){
        scanf("%d",&num);
        if(num==0){
            chain[i].isdetail=true;
            scanf("%d",&chain[i].pro);
        }
        else{
            chain[i].isdetail=false;
            chain[i].next.resize(num);
            for(j=0;j<num;j++){
                scanf("%d",&chain[i].next[j]);
            }
        }
    }
    queue<info> Q;
    Q.push(chain[0]);
    chain[0].floor=0;
    while(!Q.empty()){
        temp=Q.front();
        Q.pop();
        if(temp.isdetail) sum+=1.0*temp.pro*pow(r,temp.floor);
        else{
            int len=temp.next.size();
            for(j=0;j<len;j++){
                int u=temp.next[j];
                chain[u].floor=temp.floor+1;
                Q.push(chain[u]);
            }
        }
    }
    printf("%.1f",sum*p);
    return 0;
}
