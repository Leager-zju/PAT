#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int main(){
    int i=0,j,k;
    string input;
    unordered_map<char,bool> stuck;
    vector<char> ans;
    
    cin>>k;
    cin>>input;
    while(i<=input.length()-k){
        for(j=i+1;j<i+k;j++){
            if(input[j]!=input[i]) break;
        }
        if(j!=i+k) stuck[input[i]]=false;
        else if(stuck.find(input[i])==stuck.end()){
            stuck[input[i]]=true;

        i=j;
    }
    for(i=0;i<input.length();i++){
        if(stuck[input[i]]){
            input.erase(input.begin()+i+1,input.begin()+i+k);
        }
    }
    for(i=0;i<input.length();i++){
        if(stuck[input[i]]){
            ans.push_back(input[i]);
            stuck[input[i]]=false;
        }
    }
    for(i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    cout<<endl<<input;
}
