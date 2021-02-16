#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define maxn 1010

int totalnum,maxforward;
int follow[maxn][maxn]={0};

struct node{
    int id,floor;
}user[maxn];

void visit(node post){
    int forward=0;
    bool isvisited[maxn]={false};
    post.floor=0;
    isvisited[post.id]=true;
    queue<node> Q;
    Q.push(post);
    while(!Q.empty()){
        node top=Q.front();
        if(top.floor==maxforward) break;
        Q.pop();
        for(int i=1;i<=totalnum;i++){
            if(isvisited[i]==false && follow[top.id][i]==1){
                user[i].floor=top.floor+1;
                Q.push(user[i]);
                forward++;
                isvisited[i]=true;
            }
        }
    }
    printf("%d\n",forward);
}

int main(){
    cin>>totalnum>>maxforward;
    for(int i=1;i<=totalnum;i++){
        int num,j=0,in;
        cin>>num;
        user[i].id=i;
        while(num--){
            cin>>in;
            follow[in][i]=1;
        }
    }

    int post,postnum;
    cin>>postnum;
    while(postnum--){
        cin>>post;
        visit(user[post]);
    }
}
