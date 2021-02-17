#include<iostream>
using namespace std;

int standard[55];
struct id{
    char color;
    int number;
}card[55];

int main(){
    int k;
    int now[55],next[55];
    cin>>k;
    for(int i=1;i<=54;i++){
        cin>>standard[i];
        now[i]=i;
        if(i<=13) card[i].color='S',card[i].number=i;
        else if(i<=26) card[i].color='H',card[i].number=i-13;
        else if(i<=39) card[i].color='C',card[i].number=i-26;
        else if(i<=52) card[i].color='D',card[i].number=i-39;
        else card[i].color='J',card[i].number=i-52;
    }
    while(k--){
        for(int i=1;i<=54;i++){
            next[standard[i]]=now[i];
        }
        for(int i=1;i<=54;i++){
            now[i]=next[i];
        }
    }
    cout<<card[now[1]].color<<card[now[1]].number;
    for(int i=2;i<=54;i++){
        cout<<" "<<card[now[i]].color<<card[now[i]].number;
    }
}
