#include<string>
#include<iostream>
using namespace std;

struct node{
    string s;
    int left, right;
}tree[25];

string ans;

void postorder(int root){
    if(root != -1){
        cout << "(";
        if(tree[root].left * tree[root].right < 0) cout << tree[root].s;
        postorder(tree[root].left);
        postorder(tree[root].right);
        if(tree[root].left * tree[root].right > 0) cout << tree[root].s;
        cout << ")";
    }
}

int main(){
    int n, i;
    bool ischild[25] = {false};
    
    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> tree[i].s >> tree[i].left >> tree[i].right;
        if(tree[i].left != -1) ischild[tree[i].left] = true;
        if(tree[i].right != -1) ischild[tree[i].right] = true;
    }
    for(i = 1; i <= n; i++){
        if(!ischild[i]) break;
    }
    postorder(i);
    cout << endl;
    return 0;
}
