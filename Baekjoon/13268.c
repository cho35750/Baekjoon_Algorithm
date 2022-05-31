#include <stdio.h>

int main(){
    int dist, a;
    scanf("%d", &dist);
    dist = dist % 100;
    if(dist == 0 || dist == 10 || dist == 30 || dist == 60 || dist == 100){
        printf("%d", 0);
        return 0;
    }
    while(dist>0) {
        a=0;
        for(int i=1; i<5; i++){
            for(int j=0;j<i;j++){
                dist-=5;
                if(dist<=0){
                    a+=(5+dist);
                    break;
                }
                a+=5;
            }
            if(dist<=0) break;

            for(int j=0;j<i;j++){
                dist-=5;
                if(dist<=0){
                    a-=(5+dist);
                    break;
                }
                a-=5;
            }
            if(dist<=0) break;
        }
    }
    if(a%5==0){
        printf("%d", a/5);
        return 0;
    }
    printf("%d", a/5+1);
    return 0;
}
/*
I     I     I     I     I
0   1    2    3     4
   
5
5
10
10
15
15
20
20
=>100
*/