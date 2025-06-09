#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include "queue_struct.h"

int arr[20];
int cnt = 0;
int data_read[50];
int data_read_len = 0;
void printfArray(int* arr, int length){
    for(int i = 0; i < length; i++){
        printf("%3d", arr[i]);
    }
    printf("\n");
}

int main(void){
    static int i = 0;
    queue_t* queue = create_queue(5);
    int data_send[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    static int random = 0;
    while(1){
        // ghi du lieu
        if(random == 1){
            enqueue(queue, data_send, 20);
        }
        else{
            enqueue(queue, data_send, 10);
        }
        random = 1 - random;
        sleep(1);
        //doc du lieu
        if(dequeue(queue, data_read, &data_read_len)==QUEUE_OK){
            //xu ly du lieu
            printf("Data Read Length: %d\n", data_read_len);
            printfArray(data_read, data_read_len);
        }
        else{
            printf("Get Queue Fail");
        }

    }
    return 0;
}