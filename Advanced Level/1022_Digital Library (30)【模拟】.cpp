#include<string>
#include<unordered_map>
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,m,tag,i,j;
    char s;
    string temp,id;
    unordered_map<string,vector<string>> check[6];
    
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++){
        getline(cin,id);
        for(j=1;j<=5;j++){
            if(j==3){
                do{
                    cin>>temp;
                    check[j][temp].push_back(id);
                }while((s=getchar())!='\n');
            }
            else{
                getline(cin,temp);
                check[j][temp].push_back(id);
            }
        }
    }
    
    for(i=1;i<=5;i++){
        for(auto it=check[i].begin();it!=check[i].end();it++){
            sort(it->second.begin(),it->second.end());
        }
    }
    
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d: ",&tag);
        getline(cin,temp);
        
        printf("%d: %s\n",tag,temp.c_str());
        if(check[tag].find(temp)!=check[tag].end()){
            for(j=0;j<check[tag][temp].size();j++){
                printf("%s\n",check[tag][temp][j].c_str());
            }
        }
        else printf("Not Found\n");
    }
}
