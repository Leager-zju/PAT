#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int n,i,num,ans=0;
    scanf("%d",&n);
    int sit[n];
    for(i=0;i<n;i++){
        scanf("%d",&num);
        sit[num]=i;
    }
    for(i=0;i<n;i++){
        if(sit[i]!=i){
            while(sit[0]!=0){
                swap(sit[0],sit[sit[0]]);
                ans++;
            }
            if(sit[i]!=i){
                swap(sit[0],sit[i]);
                ans++;
            }
        }
    }
    printf("%d",ans);
}
