#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
    string a,b;
    unordered_map<char,int> check;
    getline(cin,a);
    getline(cin,b);
    int i,count=0,lenA=a.length(),lenB=b.length();
    for(i=0;i<lenA;i++){
        check[a[i]]++;
    }
    for(i=0;i<lenB;i++){
        if(check[b[i]]>0) check[b[i]]--;
        else count++;
    }
    if(count==0) cout<<"Yes "<<lenA-lenB;
    else cout<<"No "<<count;
}
