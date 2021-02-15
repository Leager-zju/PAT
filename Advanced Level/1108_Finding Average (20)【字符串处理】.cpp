#include<string>
#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

double stonum(string s){
    int len=s.length(),count=0,i;
    int flag=0,dotflag=0,numflag=0;
    double num=0;
    for(i=0;i<len;i++){
        if(i==0 && s[i]=='-'){
            flag=1;
        }
        else if(s[i]=='.'){
            if(dotflag) return -1001;
            else dotflag=1;
        }
        else if(!isdigit(s[i])) return -1001;
        else{
            numflag=1;
            num=num*10+(s[i]-'0');
            if(dotflag) count++;
        }
    }
    if(num>1000.0 || count>=3 || numflag==0) return -1001;
    num=1.0*num/pow(10,count);
    if(flag) num=-num;
    return num;
}

int main(){
    int n,i,count=0;
    double sum=0.0,num;
    cin>>n;
    string temp;
    for(i=0;i<n;i++){
        cin>>temp;
        num=stonum(temp);
        if(num!=-1001){
            sum+=num;
            count++;
        }
        else cout<<"ERROR: "<<temp<<" is not a legal number"<<endl;
    } 
    if(count==0) printf("The average of 0 numbers is Undefined");
    else if(count==1) printf("The average of 1 number is %.2lf",1.0*sum/count);
    else printf("The average of %d numbers is %.2lf",count,1.0*sum/count);
}
