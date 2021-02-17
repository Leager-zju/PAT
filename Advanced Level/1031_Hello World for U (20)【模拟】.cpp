#include<string>
#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    int N=s.length();
    int len=(N+2)/3,space=N-2*len;
    int left=0,right=s.length()-1;
    for(int i=1;i<=len-1;i++){
        cout<<s[left];
        for(int j=0;j<space;j++) cout<<" ";
        cout<<s[right]<<endl;
        left++,right--;
    }
    while(left<=right){
        cout<<s[left];
        left++;
    }
}
