#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
    int i;
    string a,b;
    unordered_map<char,bool> broken;
    getline(cin,a);
    getline(cin,b);
    for(i=0;i<a.length();i++){
        if(isalpha(a[i])) a[i]=toupper(a[i]);
        broken[a[i]]=true;
    }
    for(i=0;i<b.length();i++){
        if(isalpha(b[i])) broken[toupper(b[i])]=false;
        else broken[b[i]]=false;
    }
    for(i=0;i<a.length();i++){
        if(broken[a[i]]){
            cout<<a[i];
            broken[a[i]]=false;
        }
    }
}
