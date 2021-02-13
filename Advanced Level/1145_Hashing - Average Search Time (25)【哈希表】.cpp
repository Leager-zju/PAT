#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

bool isprime(int x){
    if(x==0||x==1) return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}

int main(){
    int n,m,tsize,i,j,num;
    double totaltime=0.0;
    cin>>tsize>>n>>m;
    while(!isprime(tsize)){
        tsize++;
    }
    
    int hash[tsize]={0};
    // 插入
    while(n--){
        cin>>num;
        for(i=0;i<tsize;i++){
            int p=(num+i*i)%tsize;
            if(hash[p]==0){
                hash[p]=num;
                break;
            }
        }
        if(i==tsize) cout<<num<<" cannot be inserted."<<endl;
    }
    // 查找
    for(i=0;i<m;i++){
        cin>>num;
        for(j=0;j<=tsize;j++){      // 这里的查找递归次数存疑,j=tsize和j=0其实是一样的下标
            totaltime++;
            int p=(num+j*j)%tsize;
            if(hash[p]==0 || hash[p]==num) break;
        }
    }
    printf("%.1f\n",totaltime/m);
}
