#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct node{
    node *left=NULL,*right=NULL;
    int data,floor;
    node(int x,int y){
        data=x;
        floor=y;
    }
};
int in[32],post[32];

node *maketree(int l1,int r1,int l2,int r2,int floor){
    if(l1>r1) return NULL;
    int i,numofleft;
    for(i=l1;i<=r1;i++){
        if(in[i]==post[r2]) break;
    }
    numofleft=i-l1;
    node *root=new node(post[r2],floor);
    root->left=maketree(l1,i-1,l2,l2+numofleft-1,floor+1);
    root->right=maketree(i+1,r1,l2+numofleft,r2-1,floor+1);
    return root;
}

vector<node*> zigzag(node *root){
    vector<node*> list;
    int i=0;
    list.push_back(root);
    while(i<list.size()){
        node *temp=list[i];
        if(temp->left) list.push_back(temp->left);
        if(temp->right) list.push_back(temp->right);
        i++;
    }
    return list;
}

int main(){
    int n,i,j;

    cin>>n;
    for(i=0;i<n;i++){
        cin>>in[i];
    }
    for(i=0;i<n;i++){
        cin>>post[i];
    }

    node* root=maketree(0,n-1,0,n-1,0);
    vector<node*> list=zigzag(root);

    i=0;
    while(i<list.size()){
        j=i+1;
        if(list[i]->floor%2==0){
            while(j<list.size() && list[j]->floor%2==0){
                j++;
            }
            reverse(list.begin()+i,list.begin()+j);
        }
        i=j;
    }

    for(i=0;i<list.size();i++){
        if(i!=0) cout<<" ";
        cout<<list[i]->data;
    }
}
