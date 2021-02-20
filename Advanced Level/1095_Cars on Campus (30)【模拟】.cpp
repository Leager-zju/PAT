#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;

struct info{
    char id[7];
    int time,tag;
}temp;

bool cmp1(info &a,info &b){
    if(strcmp(a.id,b.id)!=0) return strcmp(a.id,b.id)<0;
    else return a.time<b.time;
}

bool cmp2(info &a,info &b){
    return a.time<b.time;
}

int main(){
    int n,m,i,j;
    int hh,mm,ss,maxtime=0;
    char status[3];
    vector<info> v,list;
    map<string,int> staytime;
    
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%s %d:%d:%d %s",temp.id,&hh,&mm,&ss,status);
        temp.time=(hh*60+mm)*60+ss;
        temp.tag=(strcmp(status,"in")==0?1:-1);
        v.push_back(temp);
    }
    
    sort(v.begin(),v.end(),cmp1);
    for(i=0;i<n-1;i++){
        if(v[i].tag==1 && v[i+1].tag==-1 && strcmp(v[i].id,v[i+1].id)==0){
            list.push_back(v[i]);
            list.push_back(v[i+1]);
            staytime[v[i].id]+=v[i+1].time-v[i].time;
            maxtime=maxtime>staytime[v[i].id]?maxtime:staytime[v[i].id];
            i++;
        }
    }
    
    sort(list.begin(),list.end(),cmp2);
    int numofcars=0,last=0;
    for(i=0;i<m;i++){
        scanf("%d:%d:%d",&hh,&mm,&ss);
        n=(hh*60+mm)*60+ss;
        for(j=last;j<list.size();j++){
            if(list[j].time>n){
                last=j;
                break;
            }
            numofcars+=list[j].tag;
        }
        printf("%d\n",numofcars);
    }
    
    for(auto it=staytime.begin();it!=staytime.end();it++){
        if(it->second==maxtime) printf("%s ",it->first.c_str());
    }
    
    hh=maxtime/3600;
    mm=maxtime/60%60;
    ss=maxtime%60;
    printf("%02d:%02d:%02d\n",hh,mm,ss);
}
