// 二分查找，对于这种，在一个序列中有连续多个数求和的时候，可以用sum[]来记录从第一个数到第i个数所有数的和
// 此时 sum[j]-sum[i-1]表示i~j号数之和
// 由于sum[]为递增序列，则可用二分查找，寻找序列终点
#include<vector>
#include<iostream>
using namespace std;

vector<int> sum,result;

int main(){
    int n,pay,i,j;
    cin>>n>>pay;
    sum.resize(n+1);
    sum[0]=0;
    for(i=1;i<=n;i++){
        cin>>sum[i];
        sum[i]+=sum[i-1];
    }
    int minans=sum[n];
    for(i=1;i<=n;i++){
        int tempsum=0;
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
    for(i=0;i<result.size();i+=2){
        cout<<result[i]<<"-"<<result[i+1]<<endl;
    }
    return 0;
}
