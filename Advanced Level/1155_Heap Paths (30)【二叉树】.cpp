#include<iostream>
#include<vector>
using namespace std;


int hsize;
vector<int> heap,path;

void travel(int root){
    if(2*root>hsize){
        for(int i=0;i<path.size();i++){
            cout<<path[i];
            if(i!=path.size()-1) cout<<" ";
            else cout<<endl;
        }
        return;
    }
    for(int i=1;i>=0;i--){
        if(2*root+i>hsize) continue;
        path.push_back(heap[2*root+i]);
        travel(2*root+i);
        path.pop_back();
    }
}

int main(){
    int i;
    int ismax=1,ismin=1;
    cin>>hsize;
    heap.resize(hsize+1);
    for(i=1;i<=hsize;i++){
        cin>>heap[i];
        if(i>1 && heap[i]>heap[i/2]) ismax=0;
        if(i>1 && heap[i]<heap[i/2]) ismin=0;
    }
    path.push_back(heap[1]);
    travel(1);
    if(ismax)       cout<<"Max Heap"<<endl;
    else if(ismin)  cout<<"Min Heap"<<endl;
    else            cout<<"Not Heap"<<endl;
}
