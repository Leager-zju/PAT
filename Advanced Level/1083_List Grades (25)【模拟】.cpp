#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct info{
    string name,id;
    int grade;
};
bool cmp(info a,info b){
    return a.grade>b.grade;
}

int main(){
    int n,i,g1,g2;
    cin>>n;
    info stu[n];
    for(i=0;i<n;i++){
        cin>>stu[i].name>>stu[i].id>>stu[i].grade;
    }
    cin>>g1>>g2;
    sort(stu,stu+n,cmp);
    int count=0;
    for(i=0;i<n;i++){
        if(stu[i].grade<g1 || stu[i].grade>g2) continue;
        count=1;
        cout<<stu[i].name<<" "<<stu[i].id<<endl;
    }
    if(count==0) cout<<"NONE";
}
