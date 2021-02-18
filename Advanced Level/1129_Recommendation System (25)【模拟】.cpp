#include<set>
#include<cstdio>
using namespace std;
#define maxn 50010

struct node{
    int data,count;
    bool operator < (const node &a) const{
        if(this->count!=a.count) return this->count>a.count;
        else return this->data<a.data;
    }
};
set<node> recommend;
int times[maxn]={0};

int main(){
    int n,k,i,num;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d:",&num);
        if(i!=0){
            int count=k;
            printf("%d:",num);
            for(auto it=recommend.begin();it!=recommend.end() && count;it++){
                printf(" %d",(*it).data);
                count--;
            }
            printf("\n");
        }
        auto it=recommend.find({num,times[num]});
        if(it!=recommend.end()) recommend.erase(it);
        times[num]++;
        recommend.insert({num,times[num]});
    }
}
