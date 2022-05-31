#include <stdio.h>
#include <string.h>

int diff(char s1[], char s2[]){
    int dif = 0, min;
    if(strlen(s1) < strlen(s2)) min = strlen(s1);
    else min = strlen(s2);
    for(int i = 0; i < min; i++){
        if(s1[i] != s2[i]) dif++;
    }
    return dif;
}

int main(){
    char s1[50], s2[50];
    scanf("%s %s", s1, s2);
    int ss1 = strlen(s1), ss2 = strlen(s2);
    if(ss1 == ss2){
        printf("%d", diff(s1, s2));
        return 0;
    }
    else if(ss1 < ss2){
        int dif_min = ss1;
        for(int i = 0; i < ss2-ss1+1; i++){
            int dif_temp = 0;
            for(int j = i; j < ss1 + i; j++){
                if(s1[j-i] != s2[j]) dif_temp++;
            }
            if(dif_temp < dif_min){
                dif_min = dif_temp;
            }
        }
        printf("%d", dif_min);
        return 0;
    }
    else{
        int dif_min = ss2;
        for(int i = 0; i < ss1-ss2+1; i++){
            int dif_temp = 0;
            for(int j = i; j < ss2 + i; j++){
                if(s1[j-i] != s2[j]) dif_temp++;
            }
            if(dif_temp < dif_min){
                dif_min = dif_temp;
            }
        }
        printf("%d", dif_min);
        return 0;
    }

    return 0;
}