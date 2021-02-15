#include<queue>
#include<iostream>
using namespace std;

int main(){
    priority_queue<double,vector<double>,greater<double>> Q;
    int n,i;
    double temp,a,b;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>temp;
        Q.push(temp);
    }
    while(Q.size()!=1){
        a=Q.top();
        Q.pop();
        b=Q.top();
        Q.pop();
        Q.push(1.0*(a+b)/2);
    }
    temp=Q.top();
    printf("%d",(int)temp);
}
