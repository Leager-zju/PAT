#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(){
    int n,i,ans;
    scanf("%d",&n);
    vector<int> list(n);
    for(i=0;i<n;i++){
        scanf("%d",&list[i]);
    }
    sort(list.begin(),list.end());
    ans=list[0];
    for(i=1;i<n;i++){
        ans=(ans+list[i])/2;
    }
    printf("%d",ans);
}
