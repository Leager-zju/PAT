#include<cstdio>

int main(){
    int a1,b1,c1;
    int a2,b2,c2;
    scanf("%d.%d.%d %d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2);
    c2+=c1;
    b2+=b1;
    a2+=a1;
    
    if(c2>=29){
        c2-=29;
        b2+=1;
    }
    if(b2>=17){
        b2-=17;
        a2+=1;
    }
    printf("%d.%d.%d",a2,b2,c2);
}
