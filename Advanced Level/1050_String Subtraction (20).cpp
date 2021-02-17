#include<string>
#include<iostream>
using namespace std;

int main(){
    bool sub[128]={false};
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for(int i=0;i<b.length();i++){
        sub[b[i]]=true;
    }
    for(int i=0;i<a.length();i++){
        if(!sub[a[i]]) cout<<a[i];
    }
}
