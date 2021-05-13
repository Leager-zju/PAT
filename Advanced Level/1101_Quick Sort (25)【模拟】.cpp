#include<cstdio>

int main(){
    int lmax = -1, rmin = 1e9+7, count = 0, flag = 1;
    int n, i;
    scanf("%d", &n);
    int list[n];
    bool ispivot[n] = {false};
    
    for(i = 0; i < n; i++){
        scanf("%d", &list[i]);
        if(list[i] > lmax){
            lmax = list[i];
            ispivot[i] = true;
        }
    }
    for(i = n-1; i >= 0; i--){
        if(list[i] < rmin){
            rmin = list[i];
            if(ispivot[i]) count++;
        }
        else ispivot[i] = false;
    }
    printf("%d\n", count);
    for(i = 0; i < n; i++){
        if(ispivot[i]){
            if(flag) flag = 0;
            else printf(" ");
            printf("%d", list[i]);
        }
    }
    printf("\n");
    return 0;
}
