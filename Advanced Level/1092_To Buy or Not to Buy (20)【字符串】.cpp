#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
    string a,b;
    unordered_map<char,int> A;
    getline(cin,a);
    getline(cin,b);
    int i,count=0,lenA=a.length(),lenB=b.length();
    for(i=0;i<lenA;i++){
        A[a[i]]++;
    }
    for(i=0;i<lenB;i++){
        if(A[b[i]]>0) A[b[i]]--;
        else count++;
    }
    if(count==0) cout<<"Yes "<<lenA-lenB;
    else cout<<"No "<<count;
}
