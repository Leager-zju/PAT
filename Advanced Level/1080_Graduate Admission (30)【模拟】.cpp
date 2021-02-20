#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

struct info{
    int ge,gi,id;
    vector<int> prefer;
};

bool cmp(info &a,info &b){
    if(a.ge+a.gi!=b.ge+b.gi) return a.ge+a.gi>b.ge+b.gi;
    else return a.ge>b.ge;
}
bool cmp1(info &a,info &b){
    return a.id<b.id;
}

int main(){
    int n,m,k,i,j;
    scanf("%d %d %d",&n,&m,&k);
    
    int quota[m];
    vector<info> ranklist,school[m];
    info temp,pre;
    
    for(i=0;i<m;i++){
        scanf("%d",&quota[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d %d",&temp.ge,&temp.gi);
        temp.prefer.resize(k);
        temp.id=i;
        for(j=0;j<k;j++){
            scanf("%d",&temp.prefer[j]);
        }
        ranklist.push_back(temp);
    }
    sort(ranklist.begin(),ranklist.end(),cmp);
    for(i=0;i<n;i++){
        temp=ranklist[i];
        for(j=0;j<k;j++){
            int p=temp.prefer[j];
            int len=school[p].size();
            if(len<quota[p]){
                school[p].push_back(temp);
                break;
            }
            else{
                pre=school[p][len-1];
                if(pre.ge==temp.ge && pre.gi==temp.gi){
                    school[p].push_back(temp);
                    break;
                }
            }
        }
    }

    for(i=0;i<m;i++){
        sort(school[i].begin(),school[i].end(),cmp1);
        for(j=0;j<school[i].size();j++){
            if(j!=0) printf(" ");
            printf("%d",school[i][j].id);
        }
        printf("\n");
    }
}
