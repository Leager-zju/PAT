#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct node{
    int data;
    node *left = NULL, *right = NULL;
    node(int x): data(x) {}
};

vector<int> post,in;
int floor[1011] = {0}, parent[1011] = {0};
node *root;

node *maketree(int l1, int r1, int l2, int r2, int f){
    if(l1 > r1) return NULL;
    int i, numofleft;
    for(i = l1; i <= r1; i++){
        if(in[i] == post[r2]) break;
    }
    numofleft = i - l1;
    floor[in[i]] = f;
    node *temp = new node(in[i]);
    temp -> left = maketree(l1, i - 1, l2, l2 + numofleft - 1, f + 1);
    temp -> right = maketree(i + 1, r1, l2 + numofleft, r2 - 1, f + 1);
    if(temp -> left) parent[temp -> left -> data] = in[i];
    if(temp -> right) parent[temp -> right -> data] = in[i];
    return temp;
}

bool fulltreejudge(node *r){
    if(!r -> left && !r->right) return true;
    if(!r -> left || !r -> right) return false;
    return fulltreejudge(r -> left) && fulltreejudge(r -> right);
}

bool judge(string s){
    if(s == "It is a full tree") return fulltreejudge(root);
    int u = 0, v = 0, i;
    
    for(i = 0; i < s.length(); i++){
        if(s[i] == ' ') break;
        u = u * 10 + (s[i] - '0');
    }
    s = s.substr(i + 1);
    if(s.substr(0, 3) == "and"){
        for(i = 4; i < s.length(); i++){
            if(s[i] == ' ') break;
            v = v * 10 + (s[i] - '0');
        }
        s = s.substr(i + 1);
        if(s == "are siblings") return (parent[u] == parent[v]);
        else return (floor[u] == floor[v]);
    }
    else if(s.substr(0, 11) == "is the root") return (parent[u] == 0);
    else if(s.substr(0, 17) == "is the parent of "){
        for(i = 17; i < s.length(); i++){
            v = v * 10 + (s[i] - '0');
        }
        return (parent[v] == u);
    }
    else if(s.substr(0, 21) == "is the left child of "){
        for(i = 21; i < s.length(); i++){
            v = v * 10 + (s[i] - '0');
        }
        int p,l;
        for(i = 0; i < in.size(); i++){
            if(in[i] == u) l = i;
            if(in[i] == v) p = i;
        }
        return (l < p && parent[u] == v);
    }
    else  if(s.substr(0, 22) == "is the right child of "){
        for(i = 22; i < s.length(); i++){
            v = v * 10 + (s[i] - '0');
        }
        int p,r;
        for(i = 0; i < in.size(); i++){
            if(in[i] == u) r = i;
            if(in[i] == v) p = i;
        }
        return (r > p && parent[u] == v);
    }
}

int main(){
    int n, m, i, num;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> num;
        post.push_back(num);
    }
    for(i = 0; i < n; i++){
        cin >> num;
        in.push_back(num);
    }
    root = maketree(0, n-1, 0, n-1, 1);
    
    cin >> m;
    getchar();
    while(m--){
        string statement;
        getline(cin, statement);
        if(judge(statement)) cout << "Yes" << endl;
        else  cout << "No" << endl;
    }
}
