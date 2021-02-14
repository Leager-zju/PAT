#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

struct info{
    int address,data,next;
}list[100010];

int main(){
    int head,n,k;
    int adr,i;
    vector<info> neg,less,greater;      // 负数，0~k，k~∞
    scanf("%d %d %d",&head,&n,&k);
    while(n--){
        scanf("%d",&adr);
        list[adr].address=adr;
        scanf("%d %d",&list[adr].data,&list[adr].next);
    }
    while(head!=-1){
        if(list[head].data<0) neg.push_back(list[head]);
        else if(list[head].data<=k) less.push_back(list[head]);
        else greater.push_back(list[head]);
        head=list[head].next;
    }
    
    if(neg.size()!=0) printf("%05d %d ",neg[0].address,neg[0].data);
    for(i=1;i<neg.size();i++){
        printf("%05d\n%05d %d ",neg[i].address,neg[i].address,neg[i].data);
    }
    
    if(less.size()!=0){
        if(neg.size()!=0) printf("%05d\n",less[0].address);
        printf("%05d %d ",less[0].address,less[0].data);
    }
    for(i=1;i<less.size();i++){
        printf("%05d\n%05d %d ",less[i].address,less[i].address,less[i].data);
    }
    
    if(greater.size()!=0){
        if(less.size()!=0 || neg.size()!=0) printf("%05d\n",greater[0].address);
        printf("%05d %d ",greater[0].address,greater[0].data);
    }
    for(i=1;i<greater.size();i++){
        printf("%05d\n%05d %d ",greater[i].address,greater[i].address,greater[i].data);
    }
    
    printf("-1");
}
