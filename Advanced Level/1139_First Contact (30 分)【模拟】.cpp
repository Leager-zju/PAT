#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 10010

struct info{
    int id,gender;
}p1,p2,temp;

vector<info> relation[maxn];
bool G[maxn][maxn]={false};

bool cmp(info &a,info &b){
    if(a.id!=b.id) return a.id<b.id;
    else return a.gender<b.gender;
}
int strtonum(string s){
    int i,ans=0;
    for(i=0;i<s.length();i++){
        ans=ans*10+(s[i]-'0');
    }
    return ans;
}

int main(){
    int n,m,q,i,j;
    string a,b;
    scanf("%d %d",&n,&m);
    while(m--){
        cin>>a>>b;
        if(a[0]=='-'){
            a=a.substr(1,4);
            p1.gender=-1;
        }
        else p1.gender=1;
        if(b[0]=='-'){
            b=b.substr(1,4);
            p2.gender=-1;
        }
        else p2.gender=1;
        
        p1.id=strtonum(a);
        p2.id=strtonum(b);
        if(p1.gender==p2.gender){
            relation[p1.id].push_back(p2);
            relation[p2.id].push_back(p1);
        }
        G[p1.id][p2.id]=G[p2.id][p1.id]=true;
    }
    
    scanf("%d",&q);
    while(q--){
        vector<info> ans;
        cin>>a>>b;
        if(a[0]=='-') a=a.substr(1,4);
        if(b[0]=='-') b=b.substr(1,4);
        n=strtonum(a);
        m=strtonum(b);
        
        for(i=0;i<relation[n].size();i++){
            if(relation[n][i].id==m) continue;
            for(j=0;j<relation[m].size();j++){
                if(relation[m][j].id==n) continue;
                if(G[relation[n][i].id][relation[m][j].id]) ans.push_back({relation[n][i].id,relation[m][j].id});
            }
        }
        printf("%d\n",(int)ans.size());
        sort(ans.begin(),ans.end(),cmp);
        for(i=0;i<ans.size();i++){
            printf("%04d %04d\n",ans[i].id,ans[i].gender);
        }
    }
}
