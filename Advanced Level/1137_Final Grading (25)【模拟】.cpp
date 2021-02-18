#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;

struct info{
    string name;
    int Gp=-1,Gm=-1,Gf=-1,G;
}stu;

bool cmp(info &a,info &b){
    if(a.G!=b.G) return a.G>b.G;
    else return a.name<b.name;
}

int main(){
    unordered_map<string,info> list;
    vector<info> rank;
    string name;
    int n,m,k,grade;
    scanf("%d %d %d",&n,&m,&k);
    while(n--){
        cin>>name>>grade;
        if(grade>=200){
            list[name].Gp=grade;
        }
    }
    while(m--){
        cin>>name>>grade;
        if(list.find(name)!=list.end()) list[name].Gm=grade;
    }
    while(k--){
        cin>>name>>grade;
        if(list.find(name)!=list.end()) list[name].Gf=grade;
    }
    for(auto it=list.begin();it!=list.end();it++){
        stu=it->second;
        stu.name=it->first;
        if(stu.Gf>=stu.Gm) stu.G=stu.Gf;
        else stu.G=round(0.4*stu.Gm+0.6*stu.Gf);
        if(stu.G>=60) rank.push_back(stu);
    }
    sort(rank.begin(),rank.end(),cmp);
    for(int i=0;i<rank.size();i++){
        printf("%s %d %d %d %d\n",rank[i].name.c_str(),rank[i].Gp,rank[i].Gm,rank[i].Gf,rank[i].G);
    }
}
