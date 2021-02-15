#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,k,id,i,j,count=1,minfloor=10e7;
    double p,r;
    
    cin>>n>>p>>r;
    r=(1+r/100);
    
    vector<int> next[n];
    queue<int> Q;
    int floor[n];
    floor[0]=0;
    
    for(i=0;i<n;i++){
        cin>>k;
        for(j=0;j<k;j++){
            cin>>id;
            next[i].push_back(id);
        }
    }
    Q.push(0);
    while(!Q.empty()){
        id=Q.front();
        Q.pop();
        for(i=0;i<next[id].size();i++){
            j=next[id][i];
            Q.push(j);
            floor[j]=floor[id]+1;
            if(next[j].size()==0){
                if(floor[j]<minfloor){
                    minfloor=floor[j];
                    count=1;
                }
                else if(floor[j]==minfloor){
                    count++;
                }
            }
        }
    }
    if(n==1) minfloor=0;
    for(i=0;i<minfloor;i++){
        p*=r;
    }
    printf("%.4f %d",p,count);
}
