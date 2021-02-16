#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

int n,k,p;
int maxsum=0;
vector<int> temp,ans,list;

void search(int x,int y,int pre){
    if(x==0 && y==0){
        int sum=0;
        for(int i=0;i<temp.size();i++){
            sum+=temp[i];
        }
        if(sum>maxsum){
            maxsum=sum;
            ans=temp;
        }
    }
    else if(x>0 && y>0 && x>=y){
        for(int i=pre;list[i]>=x/y;i--){
            temp.push_back(i);
            search(x-list[i],y-1,i);
            temp.pop_back();
        }
    }
}

int main(){
    int i=0,j;
    scanf("%d %d %d",&n,&k,&p);
    while(pow(i,p)<=n){
        list.push_back(pow(i++,p)); // list[i]=pow(i,p)
    }
    j=list.size()-1;
    search(n,k,j);
    if(ans.size()==0) printf("Impossible");
    else{
        printf("%d",n);
        for(i=0;i<ans.size();i++){
            if(i==0) printf(" = ");
            else printf(" + ");
            printf("%d^%d",ans[i],p);
        }
    }
}
