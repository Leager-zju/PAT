#include<vector>
#include<iostream>
using namespace std;

vector<int> sum,result;

int main(){
    int n,pay;
    cin>>n>>pay;
    sum.resize(n+1);
    sum[0]=0;
    for(int i=1;i<=n;i++){
        cin>>sum[i];
        sum[i]+=sum[i-1];
    }
    int minans=sum[n];
    for(int i=1;i<=n;i++){
        int j,tempsum=0;
        int left=i,right=n;
        int mid;
        while(left<right){
            mid=(left+right)/2;
            if(sum[mid]-sum[i-1]>=pay) right=mid;
            else left=mid+1;
        }
        j=right;
        tempsum=sum[j]-sum[i-1];
        if(tempsum>minans) continue;
        if(tempsum>=pay){
            if(tempsum<minans){
                result.clear();
                minans=tempsum;
            }
            result.push_back(i);
            result.push_back(j);
        }
    }
    for(int i=0;i<result.size();i+=2){
        cout<<result[i]<<"-"<<result[i+1]<<endl;
    }
    return 0;
}
