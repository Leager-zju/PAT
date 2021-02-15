#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int father[1011],cluster[1011]={0};
vector<int> hobby[1011],ans;

int findfather(int x){
	int a=x,temp;
    while(father[x]!=x){
        x=father[x];
    }
	while(a!=x){
		temp=a;
		a=father[a];
		father[temp]=a;
	}
    return x;
}

void merge(int x,int y){
    int a=findfather(x);
    int b=findfather(y);
    if(a!=b) father[b]=a;
}

int main(){
    int n,i,j,k,h;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        father[i]=i;
        scanf("%d: ",&k);
        for(j=0;j<k;j++){
            scanf("%d",&h);
            hobby[h].push_back(i);
        }
    }

    for(i=1;i<=1000;i++){
        for(j=1;j<hobby[i].size();j++){
            merge(hobby[i][0],hobby[i][j]);
        }
    }

    for(i=0;i<n;i++){
        cluster[findfather(i)]++;
    }

    for(i=0;i<n;i++){
        if(cluster[i]>0) ans.push_back(cluster[i]);
    }
    sort(ans.begin(),ans.end());
    j=ans.size();
    printf("%d\n",j);
    for(i=j-1;i>=0;i--){
        printf("%d",ans[i]);
        if(i!=0) printf(" ");
    }
}
