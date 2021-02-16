#include<string>
#include<unordered_map>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct info{
    string schoolname;
    int B,A,T;
    int tws,ns;
}temp;
unordered_map<string,info> m;
vector<info> ranklist;

string lower(string s){
    string ans;
    for(int i=0;i<s.length();i++){
        ans+=tolower(s[i]);
    }
    return ans;
}
bool cmp(info a,info b){
    if(a.tws!=b.tws) return a.tws>b.tws;
    else if(a.ns!=b.ns) return a.ns<b.ns;
    else return a.schoolname<b.schoolname;
}

int main(){
    int n,i,grade;
    string id,school;
    cin>>n;
    while(n--){
        cin>>id>>grade>>school;
        school=lower(school);
        if(m.find(school)==m.end()){
            if(id[0]=='B') m[school]=info({school,grade,0,0,0,1});
            else if(id[0]=='A') m[school]=info({school,0,grade,0,0,1});
            else m[school]=info({school,0,0,grade,0,1});
        }
        else{
            if(id[0]=='B') m[school].B+=grade;
            else if(id[0]=='T') m[school].T+=grade;
            else m[school].A+=grade;
            m[school].ns++;
        }
    }
    for(auto it=m.begin();it!=m.end();it++){
        temp=it->second;
        temp.tws=temp.B/1.5+temp.A+temp.T*1.5;
        ranklist.push_back(temp);
    }
    sort(ranklist.begin(),ranklist.end(),cmp);
    int rank=1;
    cout<<(int)ranklist.size()<<endl;
    for(i=0;i<ranklist.size();i++){
        if(i!=0 && ranklist[i].tws!=ranklist[i-1].tws){
            rank=i+1;
        }
        cout<<rank<<" "<<ranklist[i].schoolname<<" "<<ranklist[i].tws<<" "<<ranklist[i].ns<<endl;
    }
}
