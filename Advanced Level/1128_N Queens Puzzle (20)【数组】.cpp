#include<cstdio>
#include<math.h>

int main(){
    int n,k,i,j,flag;
    int board[n+1];
    
    scanf("%d",&k);
    while(k--){
        flag=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&board[i]);
        }
        for(i=1;i<=n-1;i++){
            if(flag) break;
            for(j=i+1;j<=n;j++){
                if(j-i==abs(board[j]-board[i]) || board[i]==board[j]){
                    flag=1;
                    break;
                }
            }
        }
        if(flag) printf("NO\n");
        else printf("YES\n");
    }
}
