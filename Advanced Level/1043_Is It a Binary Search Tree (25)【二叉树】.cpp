#include<stdio.h>
#include<vector>
using namespace std;
struct node{
    int data;
    node *left,*right;
};
void insert(node* &root,int data){
    if(root == NULL){
        root = new node;
        root->data = data;
        root->left = root->right = NULL;
        return;
    }
    if(data < root->data){
        insert(root->left,data);
    }
    else{
        insert(root->right,data);
    }
}
void preOrder(node* root,vector<int> &vi){
    if(root == NULL){
        return;
    }
    vi.push_back(root->data);
    preOrder(root->left,vi);
    preOrder(root->right,vi);
}
void mirrorpreOrder(node* root,vector<int> &vi){
    if(root == NULL){
        return;
    }
    vi.push_back(root->data);
    mirrorpreOrder(root->right,vi);
    mirrorpreOrder(root->left,vi);
}
void postOrder(node* root,vector<int> &vi){
    if(root == NULL){
        return;
    }
    postOrder(root->left,vi);
    postOrder(root->right,vi);
    vi.push_back(root->data);
}
void mirrorpostOrder(node* root,vector<int> &vi){
    if(root == NULL){
        return;
    }
    mirrorpostOrder(root->right,vi);
    mirrorpostOrder(root->left,vi);
    vi.push_back(root->data);
}
vector<int> origin,pre,preM,post,postM;
int main(void){
    int n,data;
    node* root = NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        origin.push_back(data);
        insert(root,data);
    }
    preOrder(root,pre);
    mirrorpreOrder(root,preM);
    postOrder(root,post);
    mirrorpostOrder(root,postM);
    if(origin == pre){
        printf("YES\n");
        for(int i=0;i<post.size();i++){
            printf("%d",post[i]);
            if(i != post.size() -1){
                printf(" ");
            }
        }
    }
    else if(origin == preM){
        printf("YES\n");
        for(int i=0;i<postM.size();i++){
            printf("%d",postM[i]);
            if(i != postM.size() -1){
                printf(" ");
            }
        }
    }
    else{
        printf("NO\n");
    }
    return 0;
}
