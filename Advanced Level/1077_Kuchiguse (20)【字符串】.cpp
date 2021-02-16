#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string ans,p;
    int n,i,j;
    cin>>n;
    getchar();
    getline(cin,ans);
    reverse(ans.begin(),ans.end());
    for(i=1;i<n;i++){
        getline(cin,p);
        reverse(p.begin(),p.end());
        for(j=0;j<min(p.length(),ans.length());j++){
            if(p[j]!=ans[j]) break;
        }
        ans=ans.substr(0,j);
        if(j==0) break;
    }
    reverse(ans.begin(),ans.end());
    if(ans.length()>0) cout<<ans;
    else cout<<"nai";
    return 0;
}
