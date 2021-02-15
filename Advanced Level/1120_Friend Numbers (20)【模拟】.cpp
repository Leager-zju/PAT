#include<cstdio>
#include<map>
using namespace std;

int getFriendNumber(int x){
    int ans=0;
    while(x){
        ans+=x%10;
        x/=10;
    }
    return ans;
}

int main(){
    int n,i,count=0;
    int id,friendnum;
    map<int,int> list;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&id);
        friendnum=getFriendNumber(id);
        if(list.find(friendnum)==list.end()){
            list[friendnum]=1;
            count++;
        }
    }
    printf("%d\n",count);
    for(auto it=list.begin();it!=list.end();it++){
        if(it!=list.begin()) printf(" ");
        printf("%d",it->first);
    }
}
