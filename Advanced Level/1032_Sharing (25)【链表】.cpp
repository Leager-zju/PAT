#include<iostream>
#include<cstdio>
using namespace std;

struct node{
    char data;
    int next;
}list[100010];

int main(){
    int start1,start2,s1,s2,n;
    int n1=0,n2=0;
    int address;
    cin>>start1>>start2>>n;
    s1=start1,s2=start2;

    for(int i=0;i<n;i++){
        cin>>address;
        cin>>list[address].data>>list[address].next;
    }

    while(start1!=-1){
        start1=list[start1].next;
        n1++;
    }
    while(start2!=-1){
        start2=list[start2].next;
        n2++;
    }

    while(n2<n1&&s1!=-1){
        n2++;
        s1=list[s1].next;
    }
    while(n1<n2&&s2!=-1){
        n1++;
        s2=list[s2].next;
    }
    if(s1==-1 || s2==-1){
        cout<<"-1";
        return 0;
    }

    while(!(list[s1].data==list[s2].data && s1==s2)){
        s1=list[s1].next;
        s2=list[s2].next;
        if(s1==-1){
            cout<<"-1";
            return 0;
        }
    }
    printf("%05d",s1);
}
