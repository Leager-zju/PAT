#include <queue>
#include <cstdio>
#include <vector>
using namespace std;
#define maxn 1010

int totalnum,maxforward;
vector<int> follower[maxn];

struct node{
    int id,floor;
}user[maxn],temp;

void visit(node temp){
    bool visited[totalnum+1]={false};
    visited[temp.id]=true;
    temp.floor=0;
    int i,ans=0;
    
    queue<node> Q;
    Q.push(temp);
    while(!Q.empty()){
        temp=Q.front();
        if(temp.floor==maxforward) break;
        Q.pop();
        for(i=0;i<follower[temp.id].size();i++){
            node u=user[follower[temp.id][i]];
            if(!visited[u.id]){
                u.floor=temp.floor+1;
                ans++;
                Q.push(u);
                visited[u.id]=true;
            }
        }
    }
    printf("%d\n",ans);
}

int main(){
    int i,j,k,num;
    scanf("%d %d",&totalnum,&maxforward);
    for(i=1;i<=totalnum;i++){
        scanf("%d",&k);
        user[i].id=i;
        while(k--){
            scanf("%d",&num);
            follower[num].push_back(i);
        }
    }
    scanf("%d",&k);
    while(k--){
        scanf("%d",&num);
        visit(user[num]);
    }
}
