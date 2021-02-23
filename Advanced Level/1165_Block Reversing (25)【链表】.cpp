#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

struct info{
    int address, data, next;
}L[100010];

int main(){
    int head, n, K, i, add;
    vector<info> list;
    
    scanf("%d %d %d", &head, &n, &K);
    for(i = 0; i < n; i++){
        scanf("%d", &add);
        scanf("%d %d", &L[add].data, &L[add].next);
        L[add].address = add;
    }
    while(head != -1){
        list.push_back(L[head]);
        head = L[head].next;
    }
    for(i = 0; i < list.size(); i += K){
        if(i + K >= list.size()) reverse(list.begin() + i, list.end());
        else reverse(list.begin() + i, list.begin() + i + K);
    }
    reverse(list.begin(), list.end());
    
    for(i = 0; i < list.size(); i++){
        if(i != 0) printf("%05d\n", list[i].address);
        printf("%05d %d ", list[i].address, list[i].data);
    }
    printf("-1");
    return 0;
}
