#include<string>
#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    string s[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    string a,b,c,d;
    string ans;
    getline(cin,a);
    getline(cin,b);
    getline(cin,c);
    getline(cin,d);
    int lena=a.length(),lenb=b.length(),lenc=c.length(),lend=d.length();
    
    int i,count=1;
    for(i=0;i<min(lena,lenb);i++){
        if(a[i]==b[i]){
            if(count==1){
                if(!(a[i]>='A' && a[i]<='G')) continue;
                int d=a[i]-'A';
                cout<<s[d]<<" ";
                count++;
            }
            else if(count==2){
                int m;
                if(isdigit(a[i])) m=a[i]-'0';
                else if(a[i]>='A'&&a[i]<='N') m=a[i]-'A'+10;
                else continue;
                printf("%02d:",m);
                break;
            }
        }
    }
    for(i=0;i<min(lenc,lend);i++){
        if(c[i]==d[i] && isalpha(c[i])){
            printf("%02d",i);
            break;
        }
    }
    return 0;
}
