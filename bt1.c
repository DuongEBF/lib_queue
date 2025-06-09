#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include "Queue.h"


int arr[20];
int cnt = 0;

void printfArray(int* arr, int length){
    for(int i = 0; i < length; i++){
        printf("%3d", arr[i]);
    }
    printf("\n");
}

int main(void){
    static int i = 0;
    queue_t* queue = create_queue(5);
    while(1){
        // ghi du lieu
        enqueue(queue, i);
        i++;
        usleep(50000);
        //doc du lieu
        if(dequeue(queue, &arr[cnt])==QUEUE_OK){
            cnt++;
        }
        else{
            printf("Get Queue Fail");
        }
        if(cnt == 20){
            printfArray(arr, cnt);
            cnt = 0;
        }

    }
    return 0;
}