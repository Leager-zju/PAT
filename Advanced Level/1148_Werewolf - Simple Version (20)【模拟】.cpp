#include<cstdio>
#include<vector>
#include<math.h>
using namespace std;

int main(){
    int n,i,j,k;
    char c;
    scanf("%d",&n);
    vector<int> speak(n+1);
    for(i=1;i<=n;i++){
        scanf("%c %d",&c,&speak[i]);
        if(c=='-') speak[i]=-speak[i];
    }
    for(i=1;i<=n-1;i++){
        for(j=i+1;j<=n;j++){
            int count=0;
            vector<int> flag(n+1,1);
            vector<int> liar(n+1,1);
            flag[i]=flag[j]=-1;
            for(k=1;k<=n;k++){
                int v=abs(speak[k]);
                if(speak[k]*flag[v]<0){
                    liar[k]=-1;
                    count++;
                }
            }
            if(count==2 && liar[i]*liar[j]==-1){
                printf("%d %d\n",i,j);
                return 0;
            }
        }
    }
    printf("No Solution\n");
}
