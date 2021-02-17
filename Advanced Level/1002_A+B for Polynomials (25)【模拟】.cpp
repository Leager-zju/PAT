#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct info{
    int N;
    double a_N;
}temp;

int main(){
    int k1,k2;
    int n,a_n;
    int i=0,j=0;
    vector<info> V1,V2,V;
    
    scanf("%d",&k1);
    for(int i=0;i<k1;i++){
        scanf("%d %lf",&temp.N,&temp.a_N);
        V1.push_back(temp);
    }
    scanf("%d",&k2);
    for(int i=0;i<k2;i++){
        scanf("%d %lf",&temp.N,&temp.a_N);
        V2.push_back(temp);
    }
    while(i<V1.size() && j<V2.size()){
        if(V1[i].N>V2[j].N){
            V.push_back(V1[i]);
            i++;
        }
        else if(V1[i].N<V2[j].N){
            V.push_back(V2[j]);
            j++;
        }
        else{
            temp.N=V1[i].N;
            temp.a_N=V1[i].a_N+V2[j].a_N;
            if(temp.a_N != 0) V.push_back(temp);
            i++,j++;
        }
    }
    
    while(i<V1.size()) V.push_back(V1[i++]);
    while(j<V2.size()) V.push_back(V2[j++]);
    int count=V.size();
    printf("%d",count);
    for(int p=0;p<count;p++){
        printf(" %d %.1f",V[p].N,V[p].a_N);
    }
}
