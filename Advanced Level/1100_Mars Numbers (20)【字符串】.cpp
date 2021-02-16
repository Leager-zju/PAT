#include<string>
#include<map>
#include<iostream>
using namespace std;

string z="tret";
string d1[12]={"jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string d2[12]={"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main(){
    int i,j,n,num,flag=1;
    string temp;
    map<string,int> m;
    cin>>n;
    getchar();
    for(i=0;i<12;i++){
        m[d1[i]]=i+1;
        m[d2[i]]=(i+1)*13;
    }
    for(i=0;i<n;i++){
        getline(cin,temp);
        if(isdigit(temp[0])){
            num=0;
            flag=0;
            for(j=0;j<temp.length();j++){
                num=num*10+(temp[j]-'0');
            }
            if(num==0) cout<<z<<endl;
            else if(num<13) cout<<d1[num-1]<<endl;
            else{
                cout<<d2[num/13-1];
                if(num%13) cout<<" "<<d1[num%13-1];
                cout<<endl;
            }
        }
        else{
            if(temp==z) num=0;
            else if(temp.length()==3) num=m[temp];
            else if(temp.length()==7) num=m[temp.substr(0,3)]+m[temp.substr(4,3)];
            cout<<num<<endl;
        }
    }
}
