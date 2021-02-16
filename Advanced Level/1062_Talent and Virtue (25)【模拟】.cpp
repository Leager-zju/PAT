#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

struct info{
    int id,v,t;
}temp;

bool cmp(info &a,info &b){
    if(a.v+a.t!=b.v+b.t) return (a.v+a.t)>(b.v+b.t);
    else if(a.v!=b.v) return a.v>b.v;
    else return a.id<b.id;
}
vector<info> a,b,c,d;
int n,l,h;

int main(){
    scanf("%d %d %d",&n,&l,&h);
    int i,count=0;
    for(i=0;i<n;i++){
        scanf("%d %d %d",&temp.id,&temp.v,&temp.t);
        if(temp.v<l || temp.t<l) continue;
        count++;
        if(temp.v>=h && temp.t>=h) a.push_back(temp);
        else if(temp.v>=h) b.push_back(temp);
        else if(temp.v>=temp.t) c.push_back(temp);
        else d.push_back(temp);
    }
    sort(a.begin(),a.end(),cmp);
    sort(b.begin(),b.end(),cmp);
    sort(c.begin(),c.end(),cmp);
    sort(d.begin(),d.end(),cmp);
    printf("%d\n",count);
    for(i=0;i<a.size();i++){
        printf("%08d %d %d\n",a[i].id,a[i].v,a[i].t);
    }
    for(i=0;i<b.size();i++){
        printf("%08d %d %d\n",b[i].id,b[i].v,b[i].t);
    }
    for(i=0;i<c.size();i++){
        printf("%08d %d %d\n",c[i].id,c[i].v,c[i].t);
    }
    for(i=0;i<d.size();i++){
        printf("%08d %d %d\n",d[i].id,d[i].v,d[i].t);
    }
}
