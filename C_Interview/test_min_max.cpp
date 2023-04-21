# include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[10] = {};
    srand(0);
    for(int i = 0; i < 10; i++){
        arr[i] = rand()%100;
        printf("%d ", arr[i]);
    }
    int minnum = arr[0], maxnum = arr[0];
    float avg = 0;
    for(int i = 0; i< 10; i++){
        if(arr[i] < minnum) minnum = arr[i];
        if(arr[i] > maxnum) maxnum = arr[i];
        avg += arr[i];
    }
    avg /=10;
    printf("\nMax: %d, Min: %d, Avg.: %f\n", maxnum, minnum, avg);
}
