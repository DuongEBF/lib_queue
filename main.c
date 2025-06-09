#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


int main(void){
    int item;
    queue_t* queue = create_queue(5);
    enqueue(queue,1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    for(int i = 1; i <= 10; i++){
        enqueue(queue,4+i);
        dequeue(queue, &item);
        printf("Get Item : %d\n", item);
    }


    //dequeue(queue, &item);
    //enqueue(queue, 6);
   // printf("%d %d %d\n", item, getRear(queue), getFront(queue));
    //dequeue(queue, &item);
   // printf("%d %d\n", item, item1);
    //dequeue(queue, &item);
    //printf("%d %d\n", item, item1);
    return 0;
}