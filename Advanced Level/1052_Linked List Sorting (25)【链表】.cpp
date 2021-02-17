#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct info{
    int address,data,next;
}L[100010];

vector<info> list;
bool cmp(info a,info b){
    return a.data<b.data;
}

int main(){
    int n,head,add,count=0;
    cin>>n>>head;

    if(head==-1){
        cout<<"0 -1";
        return 0;
    }
    
    for(int i=0;i<n;i++){
        cin>>add;
        cin>>L[add].data>>L[add].next;
        L[add].address=add;
    }
    while(head!=-1){
        list.push_back(L[head]);
        count++;
        head=L[head].next;
    }
    sort(list.begin(),list.end(),cmp);
    printf("%d %05d\n%05d %d",count,list[0].address,list[0].address,list[0].data);
    for(int i=1;i<count;i++){
        printf(" %05d\n%05d %d",list[i].address,list[i].address,list[i].data);
    }
    cout<<" -1";
}
