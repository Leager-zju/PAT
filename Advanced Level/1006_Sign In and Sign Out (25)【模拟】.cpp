#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct info{
    string id,arrive,leave;
}temp;

bool cmp1(info &a,info &b){
    return a.arrive<b.arrive;
}
bool cmp2(info &a,info &b){
    return a.leave>b.leave;
}

int main(){
    vector<info> time;
    int n;
    temp.id.resize(15);
    temp.arrive.resize(8);
    temp.leave.resize(8);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s %s %s",&temp.id[0],&temp.arrive[0],&temp.leave[0]);
        time.push_back(temp);
    }
    sort(time.begin(),time.end(),cmp1);
    printf("%s",time[0].id.c_str());
    sort(time.begin(),time.end(),cmp2);
    printf(" %s",time[0].id.c_str());
}
