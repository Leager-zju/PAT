#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int i,j,n,flag;
    cin>>n;
    int list[n+1],ep[n+1];
    for(i=1;i<=n;i++){
        cin>>list[i];
    }
    for(i=1;i<=n;i++){
        cin>>ep[i];
    }
    
    for(i=2;i<=n;i++){
        if(ep[i]<ep[i-1]) break;
    }
    for(j=i;j<=n;j++){
        if(ep[j]!=list[j]) break;
    }
    if(j==n+1) flag=1;
    else flag=2;
    
    if(flag==1){
        printf("Insertion Sort\n");
        int temp=ep[i];
        while(i>1 && ep[i-1]>temp){
            ep[i]=ep[i-1];
            i--;
        }
        ep[i]=temp;
    }
    else{
        printf("Heap Sort\n");
        for(i=n;i>=1;i--){
            if(ep[i]<=ep[1]) break;
        }
        swap(ep[i],ep[1]);
        int a=1,b=2;
        while(b<=i-1){
            if(b+1<=i-1 && ep[b+1]>ep[b]) b++;
            if(ep[a]<ep[b]){
                swap(ep[a],ep[b]);
                a=b;
                b=2*a;
            }
            else break;
        }
    }
    cout<<ep[1];
    for(i=2;i<=n;i++){
        cout<<" "<<ep[i];
    }
}
