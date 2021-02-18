#include<vector>
#include<cstdio>
using namespace std;

vector<int> list;

void postorder(int root){
    if(root<list.size()){
        postorder(root*2);
        postorder(root*2+1);
        printf("%d",list[root]);
        if(i==1) printf("\n");
        else printf(" ");
    }
}

int main(){
    int n,m,i;
    scanf("%d %d",&m,&n);
    list.resize(n+1);
    while(m--){
        int ismax=1,ismin=1;
        for(i=1;i<=n;i++){
            scanf("%d",&list[i]);
            if(i>1 && list[i]>list[i/2]) ismax=0;
            if(i>1 && list[i]<list[i/2]) ismin=0;
        }
        if(ismax)       printf("Max Heap\n");
        else if(ismin)  printf("Min Heap\n");
        else            printf("Not Heap\n");
        postorder(1);
    }
}
