#ifndef _QUEUE
#define _QUEUE
#include <stdbool.h>

typedef enum{
    QUEUE_FAIL = -1,
    QUEUE_OK = 0,
}queue_stt_e;

typedef struct
{
    int front; //chi so cua phan tu dau queue
    int rear; //chi so cua phan tu cuoi queue
    int used; //so phan tu dang co trong queue
    unsigned capacity; //so phan tu toi da cua queue
    int* array; //con tro, tro den mang cua queue
}queue_t;
queue_t* create_queue(int capacity);
static bool isEmpty(queue_t* queue);
static bool isFull(queue_t* queue);
queue_stt_e enqueue(queue_t* queue, int item);
queue_stt_e dequeue(queue_t* queue, int* item);
int getFront(queue_t* queue);
int getRear(queue_t* queue);
void free_queue(queue_t* queue);
#endif