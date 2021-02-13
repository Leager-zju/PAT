#include<vector>
#include<cstdio>
using namespace std;

void postorder(vector<int> &list,int i){
    if(i<list.size()){
        postorder(list,i*2);    // 访问左子树
        postorder(list,i*2+1);  // 访问右子树
        printf("%d",list[i]);
        if(i==1) printf("\n");
        else printf(" ");
    }
}

int main(){
    int n,m,i;
    scanf("%d %d",&m,&n);
    while(m--){
        vector<int> list(n+1);
        int ismax=1,ismin=1;
        scanf("%d",&list[1]);
        for(i=2;i<=n;i++){
            scanf("%d",&list[i]);
            if(list[i]>list[i/2]) ismax=0;
            if(list[i]<list[i/2]) ismin=0;
        }
        if(ismax==1) printf("Max Heap\n");
        else if(ismin==1) printf("Min Heap\n");
        else printf("Not Heap\n");
        
        postorder(list,1);
    }
}
