#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

int maxsum=0;
vector<int> temp,ans,list;

void DFS(int n,int k,int pre,int sum){
    if(n==0 && k==0 && sum>maxsum){
        maxsum=sum;
        ans=temp;
    }
    else if(k>0 && n>=k){
        for(int i=pre;list[i]>=n/k;i--){
            temp.push_back(i);
            search(n-list[i],k-1,i,sum+i);
            temp.pop_back();
        }
    }
}

int main(){
    int n,k,p,i=0,j;
    scanf("%d %d %d",&n,&k,&p);
    while(pow(i,p)<=n){
        list.push_back(pow(i++,p)); // list[i]=pow(i,p)
    }
    j=list.size()-1;
    DFS(n,k,j,0);
    if(ans.size()!=0){
        printf("%d",n);
        for(i=0;i<ans.size();i++){
            if(i==0) printf(" = ");
            else printf(" + ");
            printf("%d^%d",ans[i],p);
        }
    }
    else printf("Impossible");
}
