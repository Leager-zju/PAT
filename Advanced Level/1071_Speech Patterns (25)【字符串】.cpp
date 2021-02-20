#include<unordered_map>
#include<string>
#include<cstdio>
using namespace std;

int main(){
    string word,ans;
    unordered_map<string,int> list;
    char c;
    int maxtime=0;
    while(1){
        c=getchar();
        if(isalpha(c)) word.push_back(tolower(c));
        else if(isdigit(c)) word.push_back(c);
        else if(word.length()!=0){
            list[word]++;
            if(maxtime<list[word]){
                ans=word;
                maxtime=list[word];
            }
            word.clear(); 
        }
        if(c=='\n') break;
    }
    printf("%s %d",ans.c_str(),maxtime);
}
