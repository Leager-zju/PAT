#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isPalindrome(string s){
    string temp=s;
    reverse(s.begin(),s.end());
    return (temp==s);
}

string AplusB(string a,string b){
    int flag=0;
    string ans;
    for(int i=0;i<a.length();i++){
        int x=a[i]-'0';
        int y=b[i]-'0';
        
        int sum=x+y+flag;
        if(sum>=10){
            flag=1;
            sum-=10;
        }
        else flag=0;
        char now=sum+'0';
        ans.push_back(now);
    }
    if(flag) ans.push_back('1');
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    int count=0;
    string n,temp;
    cin>>n;
    while(!isPalindrome(n) && count<10){
        temp=n;
        reverse(temp.begin(),temp.end());
        cout<<n<<" + "<<temp<<" = ";
        n=AplusB(n,temp);
        cout<<n<<endl;
        count++;
    }
    if(count==10) cout<<"Not found in 10 iterations.";
    else cout<<n<<" is a palindromic number.";
}
