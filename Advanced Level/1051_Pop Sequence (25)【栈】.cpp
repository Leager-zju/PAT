#include<cstdio>
#include<vector>
#include<stack>
using namespace std;

vector<int> v;
int m,n,k;

bool ispopseq(vector<int> v){
    stack<int> s;
    int maxnum=0;
    for(int i=0;i<n;i++){
        if(s.empty() || s.top()<v[i]){
            for(int j=maxnum+1;j<=v[i];j++){
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
    scanf("%d %d %d",&m,&n,&k);
    for(int i=0;i<k;i++){
        v.resize(n);
        for(int j=0;j<n;j++){
            scanf("%d",&v[j]);
        }
        if(ispopseq(v)) printf("YES\n");
        else printf("NO\n");
        v.clear();
    }
}
