#include<queue>
#include<iostream>
using namespace std;

struct node{
    int data, layer;
    node *left=NULL, *right=NULL;
    node(int x, int y): data(x), layer(y) {}
};
int in[22], pre[22];
node *maketree(int l1, int r1, int l2, int r2, int floor){
    if(l1 > r1) return NULL;
    int i, numofleft;
    for(i = l1; i <= r1 ; i++){
        if(in[i] == pre[l2]) break;
    }
    numofleft = i - l1;
    node *root = new node(in[i], floor);
    root->left = maketree(l1, i-1, l2+1, l2+numofleft, floor+1);
    root->right = maketree(i+1, r1, l2+numofleft+1, r2, floor+1);
    return root;
}

int main(){
    int n, i, first = 1;
    bool visit[22] = {false};
    
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> in[i];
    }
    for(i = 0; i < n; i++){
        cin >> pre[i];
    }
    node *root = maketree(0, n-1, 0, n-1, 0);
    queue<node*> Q;
    Q.push(root);
    while(!Q.empty()){
        root = Q.front();
        Q.pop();
        if(!visit[root->layer]){
            if(first) first = 0;
            else cout << " ";
            cout << root->data;
            visit[root->layer] = true;
        }
        if(root->left) Q.push(root->left);
        if(root->right) Q.push(root->right);
    }
    cout << "\n";
    return 0;
}
