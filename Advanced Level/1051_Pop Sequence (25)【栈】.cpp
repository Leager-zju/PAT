#include<cstdio>
#include<vector>
#include<stack>
using namespace std;

bool ispopseq(vector<int> v,int n,int m){
    stack<int> s;
    int maxnum=0,i,j;
    for(i=0;i<n;i++){
        if(s.empty() || s.top()<v[i]){
            for(j=maxnum+1;j<=v[i];j++){
                s.push(j);
            }
            int len=s.size();
            if(len>m) return false;
            s.pop();
        }
        else if(s.top()==v[i]) s.pop();
        else return false;
        maxnum=max(v[i],maxnum);
    }
    return true;
}

int main(){
    int m,n,k,i,j;
    scanf("%d %d %d",&m,&n,&k);
    for(i=0;i<k;i++){
        vector<int> v(n);
        for(j=0;j<n;j++){
            scanf("%d",&v[j]);
        }
        if(ispopseq(v,n,m)) printf("YES\n");
        else printf("NO\n");
    }
}
