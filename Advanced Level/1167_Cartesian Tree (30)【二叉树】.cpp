#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int inorder[33], first = 1;

struct node{
    int data;
    node *left = NULL, *right = NULL;
    node(int x){
        data = x;
    }
};

node *maketree(int l, int r){
    if(l > r) return NULL;
    
    int rpos = l, Min = inorder[l], i;
    for(i = l + 1; i <= r; i++){
        if(inorder[i] < Min){
            Min = inorder[i];
            rpos = i;
        }
    }
    node *root = new node(Min);
    root -> left = maketree(l, rpos - 1);
    root -> right = maketree(rpos + 1, r);
    return root;
}

void levelorder(node *root){
    queue<node*> Q;
    Q.push(root);
    while(!Q.empty()){
        root = Q.front();
        Q.pop();
        if(first) first = 0;
        else cout << " ";
        
        cout << root -> data;
        if(root -> left) Q.push(root -> left);
        if(root -> right) Q.push(root -> right);
    }
}

int main(){
    int n, i;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> inorder[i];
    }
    node *root = maketree(0, n - 1);
    levelorder(root);
    return 0;
}
