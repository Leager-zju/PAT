#include<cstdio>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct node{
    int address,data,next;
}list[100010];

int main(){
    int head,n,i,index,first=1;
    vector<node> del;
    unordered_map<int,bool> M;
    
    scanf("%d %d",&head,&n);
    for(i=0;i<n;i++){
        scanf("%d",&index);
        scanf("%d %d",&list[index].data,&list[index].next);
        list[index].address=index;
    }
    while(head!=-1){
        index=abs(list[head].data);
        if(M.find(index)==M.end()){
            if(first){
                printf("%05d %d ",list[head].address,list[head].data);
                first=0;
            }
            else printf("%05d\n%05d %d ",list[head].address,list[head].address,list[head].data);
            M[index]=true;
        }
        else del.push_back(list[head]);
        head=list[head].next;
    }
    printf("-1\n");
    if(del.size()!=0){
        printf("%05d %d ",del[0].address,del[0].data);
        for(i=1;i<del.size();i++){
            printf("%05d\n%05d %d ",del[i].address,del[i].address,del[i].data);
        }
        printf("-1\n");
    }
}
