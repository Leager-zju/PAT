#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 1011

int father[maxn],cluster[maxn]={0};
vector<int> hobby[maxn],ans;

int findfather(int x){
    int a=x;
    while(father[x]!=x){
        x=father[x];
    }
    while(a!=x){
        int temp=a;
        a=father[a];
        father[temp]=x;
    }
    return x;
}

void merge(int x,int y){
    int a=findfather(x);
    int b=findfather(y);
    if(a!=b) father[b]=a;
}

int main(){
    int n,i,j,k,h;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        father[i]=i;
        scanf("%d: ",&k);
        for(j=0;j<k;j++){
            scanf("%d",&h);
            if(hobby[h].size()!=0) merge(hobby[h][0],i);
            hobby[h].push_back(i);
        }
    }
    for(i=0;i<n;i++){
        cluster[findfather(i)]++;
    }
    for(i=0;i<n;i++){
        if(cluster[i]>0) ans.push_back(cluster[i]);
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",(int)ans.size());
    for(i=ans.size()-1;i>=0;i--){
        printf("%d",ans[i]);
        if(i!=0) printf(" ");
    }
}
