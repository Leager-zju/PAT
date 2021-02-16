#include<cstdio>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cmath>
using namespace std;

struct node{
    int address,data,next;
}list[100010];

int main(){
    int head,n,index,i,temp;
    vector<node> L,del;
    unordered_map<int,bool> M;
    
    scanf("%d %d",&head,&n);
    for(i=0;i<n;i++){
        scanf("%d",&index);
        scanf("%d %d",&list[index].data,&list[index].next);
        list[index].address=index;
    }
    temp=head;
    while(head!=-1){
        index=list[head].data;
        index=abs(index);
        if(M.find(index)==M.end()){
            L.push_back(list[head]);
            M[index]=true;
        }
        else{
            del.push_back(list[head]);
        }
        head=list[head].next;
    }
    printf("%05d %d ",L[0].address,L[0].data);
    for(i=1;i<L.size();i++){
        printf("%05d\n%05d %d ",L[i].address,L[i].address,L[i].data);
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
