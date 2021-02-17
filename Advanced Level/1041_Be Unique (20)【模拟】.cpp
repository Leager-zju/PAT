#include<unordered_map>
#include<cstdio>
using namespace std;

int main(){
    int n;
    unordered_map<int,int> m;
    scanf("%d",&n);
    
    int bet[n];
    for(int i=0;i<n;i++){
        scanf("%d",&bet[i]);
        m[bet[i]]++;
    }
    for(int i=0;i<n;i++){
        if(m[bet[i]]==1){
            printf("%d",bet[i]);
            return 0;
        }
    }
    printf("None");
    return 0;
}
