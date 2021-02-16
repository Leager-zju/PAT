#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n,i,root,count=0,top;
    int pre[100010];
    vector<int> next[100010];
    double p,r,maxprice=0.0,price[100010]={0};
    
    scanf("%d %lf %lf",&n,&p,&r);
    r=(1+0.01*r);
    
    for(i=0;i<n;i++){
        scanf("%d",&pre[i]);
        if(pre[i]==-1) root=i;
        else next[pre[i]].push_back(i);
    }
    queue<int> Q;
    Q.push(root);
    price[root]=p;
    while(!Q.empty()){
        top=Q.front();
        Q.pop();
        for(i=0;i<next[top].size();i++){
            Q.push(next[top][i]);
            price[next[top][i]]=price[top]*r;
        }
        if(i==0){
            if(price[top]>maxprice){
                maxprice=price[top];
                count=1;
            }
            else if(price[top]==maxprice){
                count++;
            }
        }
    }
    printf("%.2f %d",maxprice,count);
}
