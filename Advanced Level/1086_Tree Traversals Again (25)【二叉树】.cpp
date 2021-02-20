#include<string>
#include<stack>
#include<vector>
#include<iostream>
using namespace std;

vector<int> pre,in;
int first=1;

void maketree(int l1,int r1,int l2,int r2){
    if(l1>r1) return ;
    
    int i,numofleft;
    for(i=l2;i<=r2;i++){
        if(in[i]==pre[l1]) break;
    }
    numofleft=i-l2;
    maketree(l1+1,l1+numofleft,l2,i-1);
    maketree(l1+numofleft+1,r1,i+1,r2);
    if(first) first=0;
    else cout<<" ";
    cout<<pre[l1];
}

int main(){
    int n,i,num;
    stack<int> tree;
    string op;
    
    cin>>n;
    for(i=0;i<2*n;i++){
        cin>>op;
        if(op=="Push"){
            cin>>num;
            pre.push_back(num);
            tree.push(num);
        }
        else if(op=="Pop"){
            in.push_back(tree.top());
            tree.pop();
        }
    }
    maketree(0,n-1,0,n-1);
}
