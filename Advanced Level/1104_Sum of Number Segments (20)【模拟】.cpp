#include <iostream>
using namespace std;

int main() {
    int n,i;
    cin>>n;
    long long sum=0;
    double temp;
    for (i=1;i<=n;i++) { 
        cin>>temp;
        sum+=(long long)(temp*1000)*i*(n-i+1);
    }
    printf("%.2f", sum/1000.0);
}
