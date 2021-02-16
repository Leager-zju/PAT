#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int n,i,j,maxlen=0;
    long int p;
    scanf("%d %ld",&n,&p);
    long int seq[n];
    
    for(i=0;i<n;i++){
        scanf("%ld",&seq[i]);
    }
    sort(seq,seq+n);
    i=0,j=0;
    for(i=0;i<n;i++){
        while(j<n && seq[j]<=seq[i]*p){
            j++;
        }
        maxlen=max(maxlen,j-i);
        if(j==n) break;
    }
    printf("%d",maxlen);
}
