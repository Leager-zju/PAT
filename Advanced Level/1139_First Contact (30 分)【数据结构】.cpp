#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 10010

struct info{
    int id;
    int gender;     //1男 -1女
}p1,p2;
struct Pair{
    int u1,u2;
}temp;

vector<info> relation[maxn];
int G[maxn][maxn]={0};

bool cmp(Pair a,Pair b){
    if(a.u1!=b.u1) return a.u1<b.u1;
    else return a.u2<b.u2;
}
int strtonum(string s){
    int ans=0;
    for(int i=0;i<s.length();i++){
        ans=ans*10+(s[i]-'0');
    }
    return ans;
}

int main(){
    int n,m,q,cnt=0;
    string a,b;
    cin>>n>>m;
    while(m--){
        cin>>a>>b;
        if(a[0]=='-'){
            a=a.substr(1,4);
            p1.gender=-1;
        }
        else p1.gender=1;
        p1.id=strtonum(a);
        if(b[0]=='-'){
            b=b.substr(1,4);
            p2.gender=-1;
        }
        else p2.gender=1;
        p2.id=strtonum(b);
        if(p1.gender==p2.gender){
            relation[p1.id].push_back(p2);
            relation[p2.id].push_back(p1);
        }
        G[p1.id][p2.id]=G[p2.id][p1.id]=1;
    }
    
    cin>>q;
    while(q--){
        vector<Pair> ans;
        cin>>a>>b;
        if(a[0]=='-') a=a.substr(1,4);
        if(b[0]=='-') b=b.substr(1,4);
        n=strtonum(a);
        m=strtonum(b);
        
        for(int i=0;i<relation[n].size();i++){
            if(relation[n][i].id==m) continue;
            for(int j=0;j<relation[m].size();j++){
                if(relation[m][j].id==n) continue;
                temp.u1=relation[n][i].id;
                temp.u2=relation[m][j].id;
                if(G[temp.u1][temp.u2]){
                    ans.push_back(temp);
                }
            }
        }
        
        cout<<(int)ans.size()<<endl;
        sort(ans.begin(),ans.end(),cmp);
        for(int i=0;i<ans.size();i++){
            printf("%04d %04d\n",ans[i].u1,ans[i].u2);
        }
    }
}
