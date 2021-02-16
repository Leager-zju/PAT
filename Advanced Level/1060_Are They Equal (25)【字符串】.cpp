string transform(string s,int n){
    string ans="0.";
    int i,j,k;
    for(i=0;i<s.length();i++){
        if(s[i]=='.') break;
    }
    j=i,k=i;
    for(i=0;i<s.length();i++){
        if(s[i]!='.' && s[i]>'0'){
            k=i;
            break;
        }
    }
    int exp=(k<=j?j-k:j-k+1);
    i=0;
    while(i<n){
        if(s[k]=='.') k++;
        if(k==s.length()){
            ans+='0';
            i++;
        }
        else{
            ans+=s[k++];
            i++;
        }
    }
    ans=ans+"*10^"+to_string(exp);
    return ans;
}

int main(){
    int n;
    string a,b;
    cin>>n>>a>>b;
    a=transform(a,n);
    b=transform(b,n);
    if(a==b) cout<<"YES "<<a;
    else cout<<"NO "<<a<<" "<<b;
}
