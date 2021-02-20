#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct info{
    int address,data,next;
}l[100010];

int main(){
    int head,n,k;
    int i,addr;
    vector<info> list;
    scanf("%d %d %d",&head,&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&addr);
        scanf("%d %d",&l[addr].data,&l[addr].next);
        l[addr].address=addr;
    }
    while(head!=-1){
        list.push_back(l[head]);
        head=l[head].next;
    }
    int len=list.size();
    for(i=0;i<=len-k;i+=k){
        reverse(list.begin()+i,list.begin()+i+k);
    }
    for(i=0;i<len;i++){
        if(i==0) printf("%05d %d ",list[i].address,list[i].data);
        else printf("%05d\n%05d %d ",list[i].address,list[i].address,list[i].data);
    }
    printf("-1");
}
