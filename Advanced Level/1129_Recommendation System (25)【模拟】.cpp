#include<set>
#include<algorithm>
#include<cstdio>
using namespace std;
#define maxn 50002

int times[maxn]={0};

int main(){
    int n,k,i,temp,maxtime=1;
    scanf("%d %d",&n,&k);
    set<int> recommend[n+1];
    
    scanf("%d",&temp);
    times[temp]=1;
    recommend[1].insert(temp);
    
    for(i=1;i<n;i++){
        scanf("%d",&temp);
        printf("%d:",temp);
        
        int count=min(i,k),m=maxtime;
        while(m){
            for(auto it=recommend[m].begin();it!=recommend[m].end() && count;it++){
                printf(" %d",*(it));
                count--;
            }
            m--;
        }
        printf("\n");

        recommend[times[temp]].erase(temp);
        times[temp]++;
        recommend[times[temp]].insert(temp);
        maxtime=max(maxtime,times[temp]);
    }
}
