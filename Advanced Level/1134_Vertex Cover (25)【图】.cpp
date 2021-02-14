#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int main(){
    int v,e;    // 点数(0~v-1)，边数(0~e-1)
    int v1,v2,Q,k;
    int i,j;
    cin>>v>>e;
    
    vector<int> EdgeOfVertex[v];
    bool cover[e];
    
    for(i=0;i<e;i++){
        cin>>v1>>v2;
        EdgeOfVertex[v1].push_back(i);
        EdgeOfVertex[v2].push_back(i);
    }
    
    cin>>Q;
    while(Q--){
        cin>>k;
        int count=0;
        fill(cover,cover+e,false);
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
