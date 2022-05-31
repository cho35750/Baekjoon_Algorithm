#include <stdio.h>
int main(){
    int n, cnt = 0;
    int state[50000] = {0,};
    int time[50000][2];
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%d %d", &time[i][0], &time[i][1]);
    }

// i=0 cnt=second; cnt++;
    for(int i = 0; i < n; i++){
        int first = time[i][0];
        int second = time[i][1];
        int third = first+second;
        if(cnt % third >= second){
            cnt++;
        }
        else{
            while(cnt%third < second) cnt++;
            cnt++;
        }
    }

    printf("%d", cnt);
    return 0;
}