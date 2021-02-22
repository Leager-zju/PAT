#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int m;
vector<long long int> list;

int getsum(long long int n){
    int ans = 0;
    n += 1;
    while(n){
        ans += n%10;
        n /= 10;
    }
    return ans;
}
bool isprime(int n){
    if(n <= 2) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}
int gcd(int x, int y){
    if(y == 0) return x;
    else return gcd(y, x%y);
}
bool cmp(long long int a, long long int b){
    if(getsum(a) != getsum(b)) return getsum(a) < getsum(b);
    else return a < b;
}
void makenumber(long long int number, int sum, int k){
    if(sum > k * 9) return;
    if(k == 0){
        if(sum != 0) return;
        int v = getsum(number);
        if(!isprime(gcd(m, v))) return;
        list.push_back(number);
        return ;
    }
    for(int i = 0; i <= 9; i++){
        long long int temp = number;
        temp = temp * 10;
        makenumber(temp + i, sum - i, k - 1);
    }
}

int main(){
    int n, i, j, k;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d %d", &k, &m);
        printf("Case %d\n",i);
        for(j = 1; j <= 9; j++){
            makenumber(j, m - j, k - 1);
        }
        if(list.size() == 0){
            printf("No Solution\n");
            continue;
        }
        sort(list.begin(), list.end(), cmp);
        for(j = 0; j < list.size(); j++){
            printf("%d %lld\n", getsum(list[j]), list[j]);
        }
        list.clear();
    }
}
