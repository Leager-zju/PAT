#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<int,int> m;
    int row,col,d,maxnum=0,color;
    
    cin>>row>>col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>color;
            m[color]++;
            if(m[color]>maxnum){
                d=color;
                maxnum=m[color];
            }
        }
    }
    cout<<d;
}
