#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100010

bool present[maxn]={false};
vector<int> partner(maxn,-1);

int main(){
    int n,m,i,a,b;
    vector<int> participant,damn_single;
    
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&a,&b);
        partner[a]=b;
        partner[b]=a;
    }
    scanf("%d",&m);
    while(m--){
        scanf("%d",&a);
        present[a]=true;
        participant.push_back(a);
    }
    for(i=0;i<participant.size();i++){
        int other=partner[participant[i]];
        if(other==-1 || !present[other]) damn_single.push_back(participant[i]);
    }
    printf("%d\n",(int)damn_single.size());
    sort(damn_single.begin(),damn_single.end());
    for(i=0;i<damn_single.size();i++){
        if(i!=0) printf(" ");
        printf("%05d",damn_single[i]);
    }
}
