#include<algorithm>
#include<cstdio>
using namespace std;

int floor[1010]={0};
int maxfloor=0;

struct node{
    node *left=NULL,*right=NULL;
    int data;
    node(int x): data(x) {}
};
void maketree(node *&root,int x,int y){
    if(root==NULL){
        root=new node(x);
        maxfloor=max(maxfloor,y);
        floor[y]++;
    }
    else if(x>root->data) maketree(root->right,x,y+1);
    else maketree(root->left,x,y+1);
}

int main(){
    int n,i,temp;
    node *root=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&temp);
        maketree(root,temp,0);
    }
    if(maxfloor) printf("%d + %d = %d",floor[maxfloor],floor[maxfloor-1],floor[maxfloor]+floor[maxfloor-1]);
    else printf("%d + 0 = %d",floor[maxfloor],floor[maxfloor]);
}
