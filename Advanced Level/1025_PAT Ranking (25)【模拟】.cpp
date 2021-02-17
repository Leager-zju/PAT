#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
#define maxn 101

struct info{
    string name;
    int room;
    int grade;
    int totalrank;
    int roomrank;
}temp;
vector<info> TotalRank,Room[maxn];
bool cmp(info a,info b){
    if(a.grade!=b.grade) return a.grade>b.grade;
    else return a.name<=b.name;
}

int main(){
    int rooms,NumofStu;
    cin>>rooms;
    for(int i=0;i<rooms;i++){
        cin>>NumofStu;
        for(int j=0;j<NumofStu;j++){
            cin>>temp.name>>temp.grade;
            temp.room=i+1;
            Room[i].push_back(temp);
        }
    }
    for(int i=0;i<rooms;i++){
        sort(Room[i].begin(),Room[i].end(),cmp);
        for(int j=0;j<Room[i].size();j++){
            if(j>0 && Room[i][j].grade==Room[i][j-1].grade){
                Room[i][j].roomrank=Room[i][j-1].roomrank;
            }
            else Room[i][j].roomrank=j+1;
            TotalRank.push_back(Room[i][j]);
        }
    }
    int totalnum=TotalRank.size();
    cout<<totalnum<<endl;
    sort(TotalRank.begin(),TotalRank.end(),cmp);
    for(int i=0;i<TotalRank.size();i++){
        if(i>0 && TotalRank[i].grade==TotalRank[i-1].grade){
            TotalRank[i].totalrank=TotalRank[i-1].totalrank;
        }
        else TotalRank[i].totalrank=i+1;
        cout<<TotalRank[i].name<<" "<<TotalRank[i].totalrank<<" "<<TotalRank[i].room<<" "<<TotalRank[i].roomrank<<endl;
    }
}
