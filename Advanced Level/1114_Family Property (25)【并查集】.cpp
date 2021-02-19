// 并查集
#include<cstdio>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

struct info{
    int id;
    int numofset=0,area=0,members=0;
}property[10010];

bool cmp(int a,int b){
    if(1.0*property[a].area/property[a].members!=1.0*property[b].area/property[b].members) return 1.0*property[a].area/property[a].members>1.0*property[b].area/property[b].members;
    else return a<b;
}

int father[10000];

int findfather(int x){
    int a=x,temp;
    while(x!=father[x]){
        x=father[x];
    }
    while(a!=x){
        temp=a;
        a=father[a];
        father[temp]=a;
    }
    return x;
}

void merge(int x,int y){
    int a=findfather(x);
    int b=findfather(y);
    if(a<b) father[b]=a;
    else father[a]=b;
}

int main(){
    int n,i,j,k;
    int id,fa,mo,count=0;
    vector<int> family;
    unordered_set<int> list;
    bool flag[10010]={false};
    
    scanf("%d",&n);
    for(i=0;i<10000;i++){
        father[i]=i;
        property[i].id=i;
    }
    for(i=0;i<n;i++){
        scanf("%d %d %d",&id,&fa,&mo);
        list.insert(id);
        if(fa!=-1){
            merge(id,fa);
            list.insert(fa);
        }
        if(mo!=-1){
            merge(id,mo);
            list.insert(mo);
        }
        scanf("%d",&k);
        for(j=0;j<k;j++){
            int child;
            scanf("%d",&child);
            list.insert(child);
            merge(id,child);
        }
        scanf("%d %d",&property[id].numofset,&property[id].area);
    }

    for(auto i:list){
        int x=findfather(i);
        if(i!=x){
            property[x].numofset+=property[i].numofset;
            property[x].area+=property[i].area;
        }
        property[x].members++;
        if(!flag[x]){
            flag[x]=true;
            family.push_back(x);
            count++;
        }
    }
    printf("%d\n",count);
    sort(family.begin(),family.end(),cmp);
    for(i=0;i<family.size();i++){
        id=family[i];
        printf("%04d %d ",id,property[id].members);
        printf("%.3f %.3f\n",1.0*property[id].numofset/property[id].members,1.0*property[id].area/property[id].members);
    }
}
