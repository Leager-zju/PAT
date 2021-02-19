#include<cstdio>
#include<set>
using namespace std;

int getfriendnumber(int n){
    int ans=0;
    while(n){
        ans+=n%10;
        n/=10;
    }
    return ans;
}

int main(){
    int n,num;
    set<int> friendnumber;
    
    scanf("%d",&n);
    while(n--){
        scanf("%d",&num);
        friendnumber.insert(getfriendnumber(num));
    }
    printf("%d\n",(int)friendnumber.size());
    for(auto it=friendnumber.begin();it!=friendnumber.end();it++){
        if(it!=friendnumber.begin()) printf(" ");
        printf("%d",*it);
    }
}
