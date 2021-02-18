#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<iostream>
#include<cstdio>
using namespace std;

struct info{
    string name;
    int B=0,A=0,T=0;
    int tws=0,Ns=0;
};

bool cmp(info &a,info &b){
    if(a.tws!=b.tws) return a.tws>b.tws;
    else if(a.Ns!=b.Ns) return a.Ns<b.Ns;
    else return a.name<b.name;
}

unordered_map<string,info> list;
vector<info> ranklist;

int main(){
    int n,i,j,cnt=1;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        char id[6];
        int grade;
        string school;
        scanf("%s %d",id,&grade);
        cin>>school;
        for(j=0;j<school.length();j++){
            school[j]=tolower(school[j]);
        }
        if(id[0]=='B') list[school].B+=grade;
        else if(id[0]=='A') list[school].A+=grade;
        else if(id[0]=='T') list[school].T+=grade;
        list[school].Ns++;
    }
    for(auto it=list.begin();it!=list.end();it++){
        it->second.tws=it->second.B/1.5+it->second.A+it->second.T*1.5;
        it->second.name=it->first;
        ranklist.push_back(it->second);
    }
    sort(ranklist.begin(),ranklist.end(),cmp);
    
    printf("%d\n",(int)ranklist.size()); 
    for(i=0;i<ranklist.size();i++){
        if(i>0 && ranklist[i].tws!=ranklist[i-1].tws) cnt=i+1;
        printf("%d %s %d %d\n",cnt,ranklist[i].name.c_str(),ranklist[i].tws,ranklist[i].Ns);
    }
}
