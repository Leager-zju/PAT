#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

vector<int> cost,cp;

int main(){
    int n1,n2,i;
    int z1=0,z2=0,sum=0;
    cin>>n1;
    cost.resize(n1);
    for(i=0;i<n1;i++){
        cin>>cost[i];
        if(cost[i]>0) z1++;
    }
    cin>>n2;
    cp.resize(n2);
    for(i=0;i<n2;i++){
        cin>>cp[i];
        if(cp[i]>0) z2++;
    }
    sort(cost.begin(),cost.end());
    sort(cp.begin(),cp.end());
    
    for(i=0;i<min(z1,z2);i++){
        sum+=cost[n1-1-i]*cp[n2-1-i];
    }
    for(i=0;i<min(n1-z1,n2-z2);i++){
        sum+=cost[i]*cp[i];
    }
    cout<<sum;
}
