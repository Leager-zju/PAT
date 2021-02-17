#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

struct info{
    string id,name;
    int grade;
}temp;
bool cmp_id(info &a,info &b){
    return a.id<b.id;
}
bool cmp_name(info &a,info &b){
    if(a.name!=b.name) return a.name<b.name;
    else return a.id<b.id;
}
bool cmp_grade(info &a,info &b){
    if(a.grade!=b.grade) return a.grade<b.grade;
    else return a.id<b.id;
}

int main(){
    int n,c;
    vector<info> rank;
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>temp.id>>temp.name>>temp.grade;
        rank.push_back(temp);
    }
    if(c==1) sort(rank.begin(),rank.end(),cmp_id);
    else if(c==2) sort(rank.begin(),rank.end(),cmp_name);
    else if(c==3) sort(rank.begin(),rank.end(),cmp_grade);
    for(int i=0;i<n;i++){
        cout<<rank[i].id<<" "<<rank[i].name<<" "<<rank[i].grade<<endl;
    }
}
