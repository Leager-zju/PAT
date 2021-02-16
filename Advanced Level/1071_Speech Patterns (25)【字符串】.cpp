#include<map>
#include<string>
#include<cstdio>
using namespace std;

int main(){
    string word,ans;
    map<string,int> list;
    char c;
    int maxtime=0;
    while(1){
        c=getchar();
        if(isalpha(c)) word+=tolower(c);
        else if(isdigit(c)) word+=c;
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
