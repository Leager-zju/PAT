#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(string a,string b){
    return a+b<b+a;
}

int main(){
    int n,i;
    string ans;
    vector<string> seq;
    
    cin>>n;
    seq.resize(n);
    for(i=0;i<n;i++){
        cin>>seq[i];
    }
    sort(seq.begin(),seq.end(),cmp);
    
    for(i=0;i<n;i++){
        ans+=seq[i];
    }
    while(ans.length()>1 && ans[0]=='0') ans.erase(ans.begin());
    cout<<ans;
}
