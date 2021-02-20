#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct node{
    int data, height = 1;
    node *left = NULL, *right = NULL;
    node(int x): data(x) {}
};

int getheight(node *&root){
    if(root) return root->height;
    else return 0;
}

int getbalancefactor(node *&root){
    return getheight(root->left) - getheight(root->right);
}

void updateheight(node *&root){
    root->height = max(getheight(root->left), getheight(root->right)) + 1;
}

void L(node *&root){
    node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateheight(root);
    updateheight(temp);
    root = temp;
}

void R(node *&root){
    node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateheight(root);
    updateheight(temp);
    root = temp;
}

void insert(node *&root,int v){
    if(root == NULL){
        root = new node(v);
        return;
    }
    if(v < root->data){
        insert(root->left, v);
        updateheight(root);
        if(getbalancefactor(root) == 2){
            if(getbalancefactor(root->left) == 1) R(root);
            else if(getbalancefactor(root->left) == -1){
                L(root->left);
                R(root);
            }
        }
    }
    else{
        insert(root->right, v);
        updateheight(root);
        if(getbalancefactor(root) == -2){
            if(getbalancefactor(root->right) == -1) L(root);
            else if(getbalancefactor(root->right) == 1){
                R(root->right);
                L(root);
            }
        }
    }
}

int main(){
    int n,num;
    node *root = NULL;
    cin >> n;
    while(n--){
        cin >> num;
        insert(root, num);
    }
    cout << root->data;
}
