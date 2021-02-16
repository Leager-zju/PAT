#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

struct info{
    string id;
    int time,tag;
}temp;

bool cmp1(info &a,info &b){
    if(a.id!=b.id) return a.id<b.id;
    else return a.time<b.time;
}

bool cmp2(info &a,info &b){
    return a.time<b.time;
}

int main(){
    int n,m,i,j,hh,mm,ss,maxtime=0;
    string s;
    vector<info> l,list;
    map<string,int> staytime;
    
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        cin>>temp.id;
        scanf("%d:%d:%d",&hh,&mm,&ss);
        temp.time=(hh*60+mm)*60+ss;
        cin>>s;
        temp.tag=(s=="in"?1:-1);
        l.push_back(temp);
    }
    
    sort(l.begin(),l.end(),cmp1);
    for(i=0;i<n-1;i++){
        if(l[i].tag==1 && l[i+1].tag==-1 && l[i].id==l[i+1].id){
            list.push_back(l[i]);
            list.push_back(l[i+1]);
            staytime[l[i].id]+=l[i+1].time-l[i].time;
            maxtime=max(maxtime,staytime[l[i].id]);
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
