#include<cstdio>
#define maxn 50010

int in[maxn],pre[maxn];

int find(int l1,int r1,int l2,int r2){
    if(l1==r1) return pre[l1];
    int i,numofleft;
    for(i=l2;i<=r2;i++){
        if(in[i]==pre[l1]) break;
    }
    numofleft=i-l2;
    if(numofleft) return find(l1+1,l1+numofleft,l2,i-1);
    else return find(l1+numofleft+1,r1,i+1,r2);
}

int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&pre[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d",&in[i]);
    }
    printf("%d",find(0,n-1,0,n-1));
}
