#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

int flag=0,n,m;
vector<int> coin,temp,ans;

void DFS(int nowsum,int pos){
    if(nowsum==m){
        ans=temp;
        flag=1;
        return;
    }
    while(pos<n){
        temp.push_back(coin[pos]);
        if(nowsum+coin[pos]<=m) DFS(nowsum+coin[pos],pos+1);
        if(flag) return;
        temp.pop_back();
        pos++;
    }
}

int main(){
    int i,num;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        if(num<=m) coin.push_back(num);
    }
    sort(coin.begin(),coin.end());
    n=(int)coin.size();
    for(i=0;i<n;i++){
        temp.push_back(coin[i]);
        DFS(coin[i],i+1);
        temp.pop_back();
        if(flag) break;
    }
    if(flag){
        for(i=0;i<ans.size();i++){
            if(i!=0) printf(" ");
            printf("%d",ans[i]);
        }
    }
    else printf("No Solution");
}
