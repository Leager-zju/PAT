#include<string>
#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<vector>
using namespace std;


int main(){
    int n, m, i, count = 0;
    string id, ans;
    unordered_map<string, bool> check;
    vector<string> alumni, guest;
    id.resize(18);
    
    scanf("%d", &n);
    while(n--){
        scanf("%s", &id[0]);
        check[id] = true;
    }
    ans = id;
    scanf("%d", &m);
    while(m--){
        scanf("%s", &id[0]);
        if(check.find(id) != check.end()){
            alumni.push_back(id);
            count++;
        }
        if(count == 0) guest.push_back(id);
    }
    if(count){
        ans = alumni[0];
        for(i = 1;i < alumni.size(); i++){
            if(alumni[i].substr(6, 8) < ans.substr(6, 8)) ans = alumni[i];
        }
        
    } else {
        ans = guest[0];
        for(i = 1;i < guest.size(); i++){
            if(guest[i].substr(6, 8) < ans.substr(6, 8)) ans = guest[i];
        }
    }
    printf("%d\n%s", count, ans.c_str());
    return 0;
}
