#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;

struct info{
    string id;
    int score;
}temp;

vector<info> card;
unordered_map<string,int> num;

bool cmp(info &a,info &b){
    if(a.score!=b.score) return a.score>b.score;
    else return a.id<b.id;
}

int main(){
    int n,m,i,j,type;
    string s;
    scanf("%d %d",&n,&m);
    
    for(i=0;i<n;i++){
        cin>>temp.id>>temp.score;
        card.push_back(temp);
    }
    for(j=1;j<=m;j++){
        cin>>type>>s;
        printf("Case %d: %d %s\n",j,type,s.c_str());
        vector<info> rank;
        if(type==1){
            for(i=0;i<card.size();i++){
                if(card[i].id.substr(0,1)==s) rank.push_back(card[i]);
            }
            if(rank.size()==0) printf("NA\n");
            else{
                sort(rank.begin(),rank.end(),cmp);
                for(i=0;i<rank.size();i++){
                    printf("%s %d\n",rank[i].id.c_str(),rank[i].score);
                }
            }
        }
        else if(type==2){
            int Nt=0,Ns=0;
            for(i=0;i<card.size();i++){
                if(card[i].id.substr(1,3)==s){
                    Nt++;
                    Ns+=card[i].score;
                }
            }
            if(Nt==0) printf("NA\n");
            else printf("%d %d\n",Nt,Ns);
        }
        else if(type==3){
            num.clear();
            for(i=0;i<card.size();i++){
                if(card[i].id.substr(4,6)==s){
                    num[card[i].id.substr(1,3)]++;
                }
            }
            // 下面这部分是本题巧妙之处
            for(auto it : num) rank.push_back({it.first,it.second});
            if(rank.size()==0) printf("NA\n");
            else{
                sort(rank.begin(),rank.end(),cmp);
                for(i=0;i<rank.size();i++){
                    printf("%s %d\n",rank[i].id.c_str(),rank[i].score);
                }
            }
        }
    }
}
