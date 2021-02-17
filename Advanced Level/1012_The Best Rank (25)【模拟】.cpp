#include<map>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

struct info{
    int id,C,M,E,A,rank;
    char courses;
}temp;

bool cmp1(info &a,info &b){
    return a.A>b.A;
}
bool cmp2(info &a,info &b){
    return a.C>b.C;
}
bool cmp3(info &a,info &b){
    return a.M>b.M;
}
bool cmp4(info &a,info &b){
    return a.E>b.E;
}

int main(){
    map<int,info> gradeinfo;
    vector<info> finalRank;
    int n,m,id,i,rank;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&temp.id,&temp.C,&temp.M,&temp.E);
        temp.A=(temp.C+temp.M+temp.E)/3;
        temp.rank=n+1;
        gradeinfo[temp.id]=temp;
        finalRank.push_back(temp);
    }

    sort(finalRank.begin(),finalRank.end(),cmp1);
    rank=1;
    for(i=0;i<n;i++){
        if(i>0 && finalRank[i].A!=finalRank[i-1].A) rank=i+1;
        if(gradeinfo[finalRank[i].id].rank>rank){
            gradeinfo[finalRank[i].id].rank=rank;
            gradeinfo[finalRank[i].id].courses='A';
        }
    }
    
    sort(finalRank.begin(),finalRank.end(),cmp2);
    rank=1;
    for(i=0;i<n;i++){
        if(i>0 && finalRank[i].C!=finalRank[i-1].C) rank=i+1;
        if(gradeinfo[finalRank[i].id].rank>rank){
            gradeinfo[finalRank[i].id].rank=rank;
            gradeinfo[finalRank[i].id].courses='C';
        }
    }
    
    sort(finalRank.begin(),finalRank.end(),cmp3);
    rank=1;
    for(i=0;i<n;i++){
        if(i>0 && finalRank[i].M!=finalRank[i-1].M) rank=i+1;
        if(gradeinfo[finalRank[i].id].rank>rank){
            gradeinfo[finalRank[i].id].rank=rank;
            gradeinfo[finalRank[i].id].courses='M';
        }
    }
    
    sort(finalRank.begin(),finalRank.end(),cmp4);
    rank=1;
    for(i=0;i<n;i++){
        if(i>0 && finalRank[i].E!=finalRank[i-1].E) rank=i+1;
        if(gradeinfo[finalRank[i].id].rank>rank){
            gradeinfo[finalRank[i].id].rank=rank;
            gradeinfo[finalRank[i].id].courses='E';
        }
    }

    for(i=0;i<m;i++){
        scanf("%d",&id);
        if(gradeinfo.find(id)==gradeinfo.end()) printf("N/A\n");
        else printf("%d %c\n",gradeinfo[id].rank,gradeinfo[id].courses);
    }
}
