#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n,i,j;
    cin>>n;
    vector<int> a(n),b(n);
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        cin>>b[i];
    }
        
    for(i=0;i<n-1;i++){
        if(b[i]>b[i+1]) break;
    }
    for(j=i+1;j<n;j++){
        if(a[j]!=b[j]) break;
    }
    if(j==n){
        cout<<"Insertion Sort"<<endl;
        sort(a.begin(),a.begin()+i+2);
        for(i=0;i<n;i++){
            if(i!=0) cout<<" ";
            cout<<a[i];
        }
    }
    else{
        cout<<"Merge Sort"<<endl;
        int k=2;
        while(a!=b){
            for(i=0;i<n;i+=k){
                sort(a.begin()+i,a.begin()+min(i+k,n));
            }
            k*=2;
        }
        for(i=0;i<n;i+=k){
            sort(a.begin()+i,a.begin()+min(i+k,n));
        }
        for(i=0;i<n;i++){
            if(i!=0) cout<<" ";
            cout<<a[i];
        }
    }
    return 0;
}
