#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

struct info{
    string name;
    int height;
}stu[10010];

bool cmp(info &a,info &b){
    if(a.height!=b.height) return a.height>b.height;
    else return a.name<b.name;
}

int main(){
    int n,k,i,j,flag;
    int start,end;   
    cin>>n>>k;
    int rows=n/k;
    
    for(i=1;i<=n;i++){
        cin>>stu[i].name>>stu[i].height;
    }
    sort(stu+1,stu+n+1,cmp);

    flag=start=1;
    end=n-rows*(k-1);
    for(i=((end%2==0)?end:end-1);i>=2;i-=2){
        if(flag) flag=0;
        else cout<<" ";
        cout<<stu[i].name;
    }
    for(i=1;i<=((end%2!=0)?end:end-1);i+=2){
        if(flag) flag=0;
        else cout<<" ";
        cout<<stu[i].name;
    }
    cout<<endl;

    for(j=k-1;j>=1;j--){
        flag=1;
        start=1;
        end=rows;
        for(i=((end%2==0)?end:end-1);i>=2;i-=2){
            if(flag) flag=0;
            else cout<<" ";
            cout<<stu[i+n-rows*j].name;
        }
        for(i=1;i<=((end%2!=0)?end:end-1);i+=2){
            if(flag) flag=0;
            else cout<<" ";
            cout<<stu[i+n-rows*j].name;
        }
        cout<<endl;
    }
}
