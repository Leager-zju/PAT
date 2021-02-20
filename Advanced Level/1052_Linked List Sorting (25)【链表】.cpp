#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct info{
    int address,data,next;
}L[100010];

bool cmp(info a,info b){
    return a.data<b.data;
}

int main(){
    int n,i,head,add,count=0;
    vector<info> list;
    scanf("%d %d",&n,&head);
    for(i=0;i<n;i++){
        scanf("%d",&add);
        scanf("%d %d",&L[add].data,&L[add].next);
        L[add].address=add;
    }
    while(head!=-1){
        list.push_back(L[head]);
        count++;
        head=L[head].next;
    }
    sort(list.begin(),list.end(),cmp);
    printf("%d",count);
    for(i=0;i<count;i++){
        printf(" %05d\n%05d %d",list[i].address,list[i].address,list[i].data);
    }
    printf(" -1\n");
}
