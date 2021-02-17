#include<iostream>
#include<vector>
#include<string>
using namespace std;

char *s[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
void print(string n){
    int sum=0,i;
    vector<int> ans;
    for(i=0;i<n.length();i++){
        sum=sum+n[i]-'0';
    }
    if(sum==0){
        cout<<s[sum];
        return;
    }
    while(sum){
        ans.push_back(sum%10);
        sum/=10;
    }
    for(i=ans.size()-1;i>=0;i--){
        cout<<s[ans[i]];
        if(i!=0) cout<<" ";
    }
}

int main(){
    string n;
    cin>>n;
    print(n);
    return 0;
}
