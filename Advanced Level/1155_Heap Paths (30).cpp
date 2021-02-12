#include<iostream>
#include<vector>
using namespace std;

int ismax=1,ismin=1;
int hsize;
vector<int> heap,path;

void travel(int i){
    int j;
    if(i>hsize/2){
        for(j=0;j<path.size();j++){
            cout<<path[j];
            if(j!=path.size()-1) cout<<" ";
            else cout<<endl;
        }
        return;
    }
    for(j=1;j>=0;j--){
        if(2*i+j>hsize) continue;
        if(heap[2*i+j]>heap[i]) ismax=0;
        if(heap[2*i+j]<heap[i]) ismin=0;
        path.push_back(heap[2*i+j]);
        travel(2*i+j);
        path.pop_back();
    }
}

int main(){
    int i;
    cin>>hsize;
    heap.resize(hsize+1);
    for(i=1;i<=hsize;i++){
        cin>>heap[i];
    }
    path.push_back(heap[1]);
    travel(1);
    if(ismax==1) cout<<"Max Heap"<<endl;
    else if(ismin==1) cout<<"Min Heap"<<endl;
    else cout<<"Not Heap"<<endl;
}
