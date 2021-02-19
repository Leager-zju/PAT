#include<unordered_map>
#include<cstdio>
using namespace std;

bool isprime(int n){
    if(n==1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    unordered_map<int,int> ranklist;
    int n,m,i,id;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&id);
        ranklist[id]=i;
    }
    scanf("%d",&m);
    while(m--){
        scanf("%d",&id);
        printf("%04d: ",id);
        if(ranklist.find(id)==ranklist.end()){
            printf("Are you kidding?\n");
            continue;
        }
        else if(ranklist[id]==1) printf("Mystery Award\n");
        else if(isprime(ranklist[id])) printf("Minion\n");
        else if(ranklist[id]==0) printf("Checked\n");
        else printf("Chocolate\n");
        ranklist[id]=0;
    }
}
