#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

bool isPalindromic(vector<int> v){
    vector<int> temp=v;
    reverse(v.begin(),v.end());
    return (v==temp);
}
vector<int> Transform(int n,int base){
    vector<int> v;
    while(n){
        v.push_back(n%base);
        n/=base;
    }
    reverse(v.begin(),v.end());
    return v;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> v=Transform(n,k);
    
    if(isPalindromic(v)) printf("Yes\n");
    else printf("No\n");
    
    printf("%d",v[0]);
    for(int i=1;i<v.size();i++){
        printf(" %d",v[i]);
    }
}
