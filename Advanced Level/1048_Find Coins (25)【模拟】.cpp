#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int coin[n];
    for(int i=0;i<n;i++){
        cin>>coin[i];
    }
    sort(coin,coin+n);
    int i=0,j=n-1;
    while(i<j){
        if(coin[i]+coin[j]<m) i++;
        else if(coin[i]+coin[j]>m) j--;
        else {
            cout<<coin[i]<<" "<<coin[j];
            return 0;
        }
    }
    cout<<"No Solution";
    return 0;
}
