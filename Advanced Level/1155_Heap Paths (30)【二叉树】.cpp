#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

vector<int> temp, heap;
void dfs(int i){
    if(2*i > heap.size()){
        int n = temp.size();
        for(int j = 0; j < n; j++){
            cout << temp[j];
            if(j < n-1) cout << " ";
            else cout << endl;
        }
        return;
    }
    for(int j = 1; j >= 0; j--){
        if(2*i+j < heap.size()){
            temp.push_back(heap[2*i+j]);
            dfs(2*i+j);
            temp.pop_back();
        }
    }
}
int main(){
    int n, i, ismax = 1, ismin = 1;

    cin >> n;
    heap.resize(n+1);
    for(i = 1; i <= n; i++){
        cin >> heap[i];
        if(i > 1){
            if(heap[i] > heap[i/2]) ismax = 0;
            if(heap[i] < heap[i/2]) ismin = 0;
        }
    }
    temp.push_back(heap[1]);
    dfs(1);
    if(ismax) cout << "Max Heap";
    else if(ismin) cout << "Min Heap";
    else cout << "Not Heap";
    return 0;
}
