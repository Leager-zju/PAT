#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    long long int num,q;
    vector<int> ans,temp;
    int i,j,k;
    int maxlen=0,templen;
    
    cin>>num;
    q=ceil(sqrt(num));
    
    for(i=2;i<=q;i++){
        k=1;
        templen=0;
        temp.clear();
        for(j=i;j<=q;j++){
            k*=j;
            if(num%k!=0) break;
            temp.push_back(j);
            templen++;
        }
        if(templen>maxlen){
            maxlen=templen;
            ans=temp;
        }
    }
    if(maxlen==0){
        cout<<"1"<<endl<<num;
        return 0;
    }
    cout<<maxlen<<endl;
    for(i=0;i<maxlen;i++){
        if(i!=0) cout<<"*";
        cout<<ans[i];
    }
}
