#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

struct node{
    int data;
    vector<int> child;
};
int n,m,s;
vector<int> path;
vector<node> tree;

void DFS(int root,int sum){
    if(sum==s && tree[root].child.size()==0){
        for(int i=0;i<path.size();i++){
            if(i!=0) cout<<" ";
            cout<<path[i];
        }
        cout<<endl;
        return;
    }
    for(int i=tree[root].child.size()-1;i>=0;i--){
        int u=tree[root].child[i];
        if(sum+tree[u].data>s) continue;
        path.push_back(tree[u].data);
        DFS(u,sum+tree[u].data);
        path.pop_back();
    }
}

bool cmp(int a,int b){
    return tree[a].data<tree[b].data;
}

int main(){
    int i,j,k,id;
    cin>>n>>m>>s;
    tree.resize(n);
    
    for(i=0;i<n;i++){
        cin>>tree[i].data;
    }
    for(i=0;i<m;i++){
        cin>>id>>k;
        tree[id].child.resize(k);
        for(j=0;j<k;j++){
            cin>>tree[id].child[j];
        }
        sort(tree[id].child.begin(),tree[id].child.end(),cmp);
    }
    path.push_back(tree[0].data);
    DFS(0,tree[0].data);
}
