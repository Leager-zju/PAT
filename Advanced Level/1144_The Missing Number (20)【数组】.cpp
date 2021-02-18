#include<unordered_map>
#include<cstdio>
using namespace std;

int main(){
    int n,num,i,temp=1;
    unordered_map<int,int> mp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        if(num>0) mp[num]=1;
        while(mp[temp]){
            temp++;
        }
    }
    printf("%d",temp);
}
