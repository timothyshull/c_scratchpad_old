#ifndef RING_BUFFER_RINGBUFFER_H
#define RING_BUFFER_RINGBUFFER_H

#include <stdbool.h>

typedef struct Node Node;
typedef void *Data;
typedef struct RingBuffer RingBuffer;
typedef struct ListIterator ListIterator;

// temp
char *Data_toString(Data data);

RingBuffer *RingBuffer_create();

void RingBuffer_init(RingBuffer *const this);

void RingBuffer_dealloc(RingBuffer *this);

void RingBuffer_destroy(RingBuffer *this);

bool RingBuffer_isEmpty(const RingBuffer *this);

int RingBuffer_size(const RingBuffer *this);

Data RingBuffer_peek(RingBuffer *this);

void RingBuffer_enqueue(RingBuffer *this, Data item);

Data RingBuffer_dequeue(RingBuffer *this);

char *RingBuffer_toString(RingBuffer *this);

// check internal invariants
bool RingBuffer_check(RingBuffer *this);

void ListIterator_init(ListIterator *this, RingBuffer *target);

bool ListIterator_hasNext(ListIterator *this);

Data ListIterator_next(ListIterator *this);

#endif //RING_BUFFER_RINGBUFFER_H
