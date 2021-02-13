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
        scanf("%c%d",&c,&speak[i]);
        if(c=='-') speak[i]=-speak[i];
    }
    for(i=1;i<=n-1;i++){
        for(j=i+1;j<=n;j++){
            int count=0;
            vector<int> flag(n+1,1);    // 身份:        -1:狼 1:人
            vector<int> liar(n+1,1);    // 发言可信度:  -1:假 1:真

            flag[i]=flag[j]=-1;         // 假设i,j均为狼人
            
            for(k=1;k<=n;k++){
                int v=abs(speak[k]);    // v:玩家k指认的对象
                if(speak[k]*flag[v]<0){ // 如果k的发言和假设情况不符，则k说谎
                    liar[k]=-1;
                    count++;
                }
            }
            if(count==2 && liar[i]*liar[j]==-1){    // 若 i,j 一个说谎一个没说谎，则都是狼人
                printf("%d %d\n",i,j);
                return 0;
            }
        }
    }
    if(i==n) printf("No Solution\n");
}
