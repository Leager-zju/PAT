#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int main(){
    int v,e,i,j;
    int v1,v2,Q,k;
    vector<int> EdgeOfVertex[10010];
    
    cin>>v>>e;
    for(i=0;i<e;i++){
        cin>>v1>>v2;
        EdgeOfVertex[v1].push_back(i);
        EdgeOfVertex[v2].push_back(i);
    }
    cin>>Q;
    while(Q--){
        cin>>k;
        int count=0;
        bool cover[e]={false};
        while(k--){
            cin>>v;
            for(i=0;i<EdgeOfVertex[v].size();i++){
                if(!cover[EdgeOfVertex[v][i]]){
                    cover[EdgeOfVertex[v][i]]=true;
                    count++;
                }
            }
        }
        if(count==e) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
