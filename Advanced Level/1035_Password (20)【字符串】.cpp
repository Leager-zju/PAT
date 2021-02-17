#include<string>
#include<vector>
#include<iostream>
using namespace std;

struct info{
    string act,psw;
}temp;
vector<info> modify;
int flag;

string transform(string p){
    for(int i=0;i<p.length();i++){
        if(p[i]=='1'){
            p[i]='@';
            flag=1;
        }
        else if(p[i]=='0'){
            p[i]='%';
            flag=1;
        }
        else if(p[i]=='l'){
            p[i]='L';
            flag=1;
        }
        else if(p[i]=='O'){
            p[i]='o';
            flag=1;
        }
    }
    return p;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp.act>>temp.psw;
        flag=0;
        temp.psw=transform(temp.psw);
        if(flag) modify.push_back(temp);
    }
    if(modify.size()==0){
        if(n==1) cout<<"There is 1 account and no account is modified";
        else cout<<"There are "<<n<<" accounts and no account is modified";
    }
    else{
        int N=modify.size();
        cout<<N<<endl;
        for(int i=0;i<N;i++){
            cout<<modify[i].act<<" "<<modify[i].psw<<endl;
        }
    }
}
