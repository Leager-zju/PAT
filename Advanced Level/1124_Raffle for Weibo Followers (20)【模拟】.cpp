#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;

int main(){
    int i,n,m,s;
    cin>>n>>m>>s;
    getchar();
    string id[n];
    unordered_map<string,bool> check;
    for(i=0;i<n;i++){
        getline(cin,id[i]);
        check[id[i]]=false;
    }
    if(n<s) cout<<"Keep going...";
    else{
        for(i=s-1;i<n;i+=m){
            if(!check[id[i]]){
                check[id[i]]=true;
                cout<<id[i]<<endl;
            }
            else{
                while(check[id[i]] && i<n){
                    i++;
                }
                if(i!=n) cout<<id[i]<<endl;
            }
        }
    }
}
