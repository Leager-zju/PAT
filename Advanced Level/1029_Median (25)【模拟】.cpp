#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
#define mid (n1+n2+1)/2

int main(){
    int n1,n2,i,j,count=0;
    vector<long int> list1,list2;
    cin>>n1;
    list1.resize(n1);
    for(i=0;i<n1;i++){
        cin>>list1[i];
    }
    cin>>n2;
    list2.resize(n2);
    for(i=0;i<n2;i++){
        cin>>list2[i];
    }
    i=j=0;
    while(count<mid && i<n1 && j<n2){
        if(list1[i]<=list2[j]){
            count++;
            if(count==mid){
                cout<<list1[i];
                return 0;
            }
            i++;
        }
        else if(list1[i]>=list2[j]){
            count++;
            if(count==mid){
                cout<<list2[j];
                return 0;
            }
            j++;
        }
    }
    while(i<n1){
        count++;
        if(count==mid){
            cout<<list1[i];
            return 0;
        }
        i++;
    }
    while(j<n2){
        count++;
        if(count==mid){
            cout<<list2[j];
            return 0;
        }
        j++;
    }
}
