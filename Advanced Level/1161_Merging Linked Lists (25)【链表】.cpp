#include<vector>
#include<cstdio>
using namespace std;

struct node{
    int address, data, next;
}list[100010];

void merge(vector<node> &list1, vector<node> &list2){
    int i, j;
    j = list2.size() - 1;
    for(i = 0 ; i < list1.size(); i++){
        if(i != 0) printf("%05d\n",list1[i].address);
        printf("%05d %d ", list1[i].address, list1[i].data);
        if((i + 1) % 2 == 0 && j >= 0){
            printf("%05d\n%05d %d ", list2[j].address, list2[j].address, list2[j].data);
            j--;
        }
    }
    printf("-1");
}

int main(){
    int head1, head2, n, i, j, p;
    int cnt1 = 0, cnt2 = 0;
    vector<node> list1, list2;
    
    scanf("%d %d %d", &head1, &head2, &n);
    for(i = 0; i < n ; i++){
        scanf("%d", &p);
        scanf("%d %d", &list[p].data, &list[p].next);
        list[p].address = p;
    }
    while(head1 != -1){
        list1.push_back(list[head1]);
        head1 = list[head1].next;
        cnt1++;
    }
    while(head2 != -1){
        list2.push_back(list[head2]);
        head2 = list[head2].next;
        cnt2++;
    }

    if(cnt1 > cnt2) merge(list1, list2);
    else merge(list2, list1);
}
