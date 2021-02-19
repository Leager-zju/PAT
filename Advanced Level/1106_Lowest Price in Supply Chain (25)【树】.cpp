#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
#define maxn 100010

int main(){
    double p,r;
    int n,k,id,i;
    int count=1,minfloor=10e7;
    int floor[maxn];
    queue<int> Q;
    vector<int> next[maxn];
    
    scanf("%d %lf %lf",&n,&p,&r);
    for(i=0;i<n;i++){
        scanf("%d",&k);
        while(k--){
            scanf("%d",&id);
            next[i].push_back(id);
        }
    }
    
    Q.push(0);
    floor[0]=0;
    while(!Q.empty()){
        id=Q.front();
        Q.pop();
        for(i=0;i<next[id].size();i++){
            Q.push(next[id][i]);
            floor[next[id][i]]=floor[id]+1;
        }
        if(next[id].size()==0){
            if(floor[id]<minfloor){
                minfloor=floor[id];
                count=1;
            }
            else if(floor[id]==minfloor) count++;
        }
    }
    r=(1+r/100);
    while(minfloor--){
        p*=r;
    }
    printf("%.4f %d\n",p,count);
}
