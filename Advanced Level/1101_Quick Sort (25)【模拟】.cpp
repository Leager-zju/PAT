#include<iostream>
#include<vector>
using namespace std;

int main(){
    int lmax=-1,rmin=10e9+1;
    int n,i;
    cin>>n;
    vector<int> list(n),pivot;
    bool ispivot[n];
    
    for(i=0;i<n;i++){
        cin>>list[i];
    }
    for(i=n-1;i>=0;i--){
        if(list[i]<rmin){
            rmin=list[i];
            ispivot[i]=true;
        }
        else ispivot[i]=false;
    }
    for(i=0;i<n;i++){
        if(list[i]>lmax){
            lmax=list[i];
            if(!ispivot[i]) continue;
            pivot.push_back(list[i]);
        }
    }
    i=pivot.size();
    cout<<i<<endl;
    for(i=0;i<pivot.size();i++){
        cout<<pivot[i];
        if(i!=pivot.size()-1) cout<<" ";
    }
    cout<<endl;
}
