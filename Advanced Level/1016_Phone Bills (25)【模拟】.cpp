#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;

struct info{
    int M,d,h,m;
    string tag;
}temp;

bool cmp(info &a,info &b){
    if(a.M!=b.M) return a.M<b.M;
    else if(a.d!=b.d) return a.d<b.d;
    else if(a.h!=b.h) return a.h<b.h;
    else return a.m<b.m;
}

string name;
map<string,vector<info>> bill;
int toll[24];
double alldaycost=0.0;

int main(){
    int n,i,j;
    for(i=0;i<24;i++){
        cin>>toll[i];
        alldaycost+=toll[i]*0.6;
    }
    cin>>n;
    for(i=0;i<n;i++){
        cin>>name;
        scanf("%d:%d:%d:%d",&temp.M,&temp.d,&temp.h,&temp.m);
        cin>>temp.tag;
        bill[name].push_back(temp);
    }
    for(auto it=bill.begin();it!=bill.end();it++){
        vector<info> v(it->second.begin(),it->second.end());
        sort(v.begin(),v.end(),cmp);
        double totalcost=0.0;
        int flag=1;
        for(i=1;i<v.size();i++){
            if(v[i].tag=="off-line" && v[i-1].tag=="on-line"){
                if(flag){
                    flag=0;
                    printf("%s %02d\n",it->first.c_str(),it->second[0].M);
                }
                double cost=0.0;
                printf("%02d:%02d:%02d ",v[i-1].d,v[i-1].h,v[i-1].m);
                printf("%02d:%02d:%02d ",v[i].d,v[i].h,v[i].m);
                printf("%d ",(v[i].d-v[i-1].d)*1440+(v[i].h-v[i-1].h)*60+v[i].m-v[i-1].m);

                if(v[i-1].h<=v[i].h){
                    for(j=v[i-1].h;j<v[i].h;j++){
                        cost+=toll[j]*0.6;
                    }
                    cost+=0.01*(v[i].m*toll[v[i].h]-v[i-1].m*toll[v[i-1].h]);
                    cost+=alldaycost*(v[i].d-v[i-1].d);
                }
                else{
                    cost=alldaycost;
                    for(j=v[i].h;j<v[i-1].h;j++){
                        cost-=toll[j]*0.6;
                    }
                    cost+=0.01*(v[i].m*toll[v[i].h]-v[i-1].m*toll[v[i-1].h]);
                    cost+=alldaycost*(v[i].d-v[i-1].d-1);
                }
                totalcost+=cost;
                printf("$%.2f\n",cost);
            }
        }
        if(!flag) printf("Total amount: $%.2f\n",totalcost);
    }
}
