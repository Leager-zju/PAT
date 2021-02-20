#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    long long int num,q;
    vector<int> ans,temp;
    int i,j,product;
    int maxlen=0,templen;
    
    cin>>num;
    q=sqrt(num)+1;
    for(i=2;i<=q;i++){
        product=1;
        templen=0;
        temp.clear();
        for(j=i;j<=q;j++){
            product*=j;
            if(num%product!=0) break;
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
