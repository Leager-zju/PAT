#include<set>
#include<iostream>
using namespace std;

int main(){
    int n, k, i, cnt = 0, first, out;
    cin >> n >> k;
    bool visit[n] = {false};
    int list[n];
    for(i = 0; i < n; i++){
        cin >> list[i];
    }

    while(cnt < n){
        multiset<int> temp;
        first = 1;
        int capacity = k;
        for(i = 0; i < n && temp.size() < k; i++){
            if(visit[i]) continue;
            temp.insert(list[i]);
            visit[i] = true;
            cnt++;
        }
        for(i = 0; i < n && temp.size() != 0; i++){
            if(visit[i]) continue;
            out = *temp.begin();
            if(first) first = 0;
            else cout << " ";
            cout << out;
            temp.erase(temp.begin());
            if(list[i] >= out && temp.size() < capacity){
                temp.insert(list[i]);
                visit[i] = true;
                cnt++;
            }
            else if(list[i] < out) capacity--;
        }
        for(auto it : temp){
            if(first) first = 0;
            else cout << " ";
            cout << it;
        }
        cout << endl;
    }
    return 0;
}
