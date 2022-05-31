#include <stdio.h>

int main(){
    int testcase;
    scanf("%d", &testcase);
    for(int i=0; i<testcase; i++){
        int measure=0;
        scanf("%d", &measure);
        int left[200], right[200];
        int l2r = 0;
        for(int j=0;j<measure;j++){
            scanf("%d", &left[j]);
        }
        for(int j=0;j<measure;j++){
            scanf("%d", &right[j]);
        }
        for(int j=0;j<measure;j++){
            if(left[j] < right[j]) l2r++;
        }
        printf("%d", l2r/2);
    }
    return 0;
}