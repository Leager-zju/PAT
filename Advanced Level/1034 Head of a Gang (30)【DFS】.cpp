#include <map>
#include <iostream>
#include <string>
using namespace std;

int n,k,totalnum=0;
int G[2010][2010]={0};
bool Isvisited[2010]={false};
int perWeight[2010]={0};

map<string,int> m1;
map<int,string> m2;
map<string,int> Gang;

int change(string a){
    if(m1.find(a)!=m1.end()) return m1[a];
    else{
        m1[a]=totalnum;
        m2[totalnum]=a;
        return totalnum++;
    }
}

void visit(int nowvisit,int &num,int &head,int &sumweight){
    Isvisited[nowvisit]=true;
    num++;
    if(perWeight[head]<perWeight[nowvisit]) head=nowvisit;
    for(int i=0;i<totalnum;i++){
        if(G[nowvisit][i]!=0){
            sumweight+=G[nowvisit][i];
            G[nowvisit][i]=G[i][nowvisit]=0;
            if(Isvisited[i]==false) visit(i,num,head,sumweight);
        }
    }
}

int main(){
    int w,p1,p2,i;
    string str1,str2;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>str1>>str2>>w; 
        p1=change(str1);
        p2=change(str2);
        perWeight[p1]+=w;
        perWeight[p2]+=w;
        G[p1][p2]+=w;
        G[p2][p1]+=w;
    }
    for(i=0;i<totalnum;i++){
        if(!Isvisited[i]){
            int num=0,head=i,sumweight=0;
            visit(i,num,head,sumweight);
            if(sumweight>k && num>2){
                Gang[m2[head]]=num;
            }
        }
    }
    cout<<Gang.size()<<endl;
    for(auto it=Gang.begin();it!=Gang.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}
