#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct info{
    int address,data,next;
}l[100010];

int main(){
    int head,n,k;
    int i,add;
    vector<info> list;
    scanf("%d %d %d",&head,&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&add);
        scanf("%d %d",&l[add].data,&l[add].next);
        l[add].address=add;
    }
    if(head==-1){
        printf("-1");
        return 0;
    }
    while(head!=-1){
        list.push_back(l[head]);
        head=l[head].next;
    }
    int len=list.size();
    for(i=0;i<len;i+=k){
        if(i+k>len) break;
        else reverse(list.begin()+i,list.begin()+i+k);
    }
    printf("%05d %d",list[0].address,list[0].data);
    for(i=1;i<len;i++){
        printf(" %05d\n%05d %d",list[i].address,list[i].address,list[i].data);
    }
    printf(" -1");
}
