#include<cstdio>
#include<math.h>

int main(){
    int n,k,i,j;
    scanf("%d",&k);
    while(k--){
        scanf("%d",&n);
        int board[n+1],flag=0;
        for(i=1;i<=n;i++){
            scanf("%d",&board[i]);
            if(flag) continue;
            for(j=1;j<i;j++){
                if(i-j==abs(board[i]-board[j]) || board[i]==board[j]) flag=1;
            }
        }
        if(flag) printf("NO\n");
        else printf("YES\n");
    }
}
