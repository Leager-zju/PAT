#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,m,i,j,k,lesson;
    char id[4];
    scanf("%d %d",&n,&m);
    vector<string> list[n];
    for(i=0;i<n;i++){
        scanf("%s %d",id,&k);
        for(j=0;j<k;j++){
            scanf("%d",&lesson);
            list[lesson-1].push_back(id);
        }
    }
    for(i=0;i<m;i++){
        printf("%d %d\n",i+1,(int)list[i].size());
        sort(list[i].begin(),list[i].end());
        for(j=0;j<list[i].size();j++){
            printf("%s\n",list[i][j].c_str());
        }
    }
}
