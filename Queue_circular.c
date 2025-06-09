#include "Queue.h"
#include <stdlib.h>
#include <stdbool.h>
queue_t* create_queue(int capacity){
    queue_t* qt = (queue_t*)malloc(1*sizeof(queue_t));
    qt->front = 0;
    qt->rear = -1;
    qt->used = 0;
    qt->capacity = capacity;
    qt->array = (int*)malloc(capacity*sizeof(int));
    return qt;
}

static bool isEmpty(queue_t* queue){
    return (queue->used == 0);
}
static bool isFull(queue_t* queue){
    return (queue->used == queue->capacity);
}

int getFront(queue_t* queue){
    return queue->array[queue->front];
}

int getRear(queue_t* queue){
    return queue->array[queue->rear];
}

queue_stt_e enqueue(queue_t* queue, int item){
    if(isFull(queue)){ //neu full thi k add nua
        return QUEUE_FAIL;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->used++;
    return QUEUE_OK;
}


queue_stt_e dequeue(queue_t* queue, int* item){
    if(isEmpty(queue)){
        return QUEUE_FAIL;
    }
    *item = queue->array[queue->front];
    queue->front = (queue->front+1)%queue->capacity;
    queue->used--;
    return QUEUE_OK;
}

void free_queue(queue_t* queue) {
    if (queue == NULL) return;

    // Giải phóng mảng bên trong nếu đã được cấp phát
    if (queue->array != NULL) {
        free(queue->array);
    }

    // Giải phóng struct queue_t
    free(queue);
}