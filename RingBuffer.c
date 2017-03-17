#include "RingBuffer.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <memory.h>

typedef struct Node {
    Data item;
    Node *next;
} Node;

typedef struct RingBuffer {
    Node *first;
    Node *last;
    int n;
} RingBuffer;

char *Data_toString(Data data) {
    const char *fmt = "Data: %d,\n";
    int sz = snprintf(NULL, 0, fmt, *((char *) data));
    char *buf = (char *) malloc(sizeof(char) * (sz + 1));
    snprintf(buf, sizeof buf, fmt, *((char *) data));
    // buf needs to be freed later
    return buf;
}

void RingBuffer_init(RingBuffer *const this) {
    this->first = NULL;
    this->last = NULL;
    this->n = 0;
}

RingBuffer *RingBuffer_create() {
    size_t rbSize = sizeof(RingBuffer);
    RingBuffer *this = (RingBuffer *) malloc(rbSize);
    RingBuffer_init(this);
    assert(RingBuffer_check(this));
    return this;
}

void RingBuffer_dealloc(RingBuffer *this) {
    this->n = 0;
    // TODO: need to change this to loop from first to last
    Node *tmp = this->first;
    if (tmp != NULL) {
        while (tmp->next != this->last) {

        }
    }

    if (this->last != NULL) {
        free(this->last);
        this->last = NULL;
    }
    if (this->first != NULL) {
        free(this->first);
        this->first = NULL;
    }
}

void RingBuffer_destroy(RingBuffer *this) {
    if (this != NULL) {
        RingBuffer_dealloc(this);
        free(this);
    }
}

bool RingBuffer_isEmpty(const RingBuffer *this) {
    return this->first == NULL;
}

int RingBuffer_size(const RingBuffer *this) {
    return this->n;
}

Data RingBuffer_peek(RingBuffer *this) {
    if (RingBuffer_isEmpty(this)) {
        // throw error here?
        abort();
    }
    return this->first->item;
}

void RingBuffer_enqueue(RingBuffer *this, Data item) {
    Node *oldlast = this->last;
    this->last = (Node *) malloc(sizeof(Node));
    this->last->item = item;
    this->last->next = NULL;
    if (RingBuffer_isEmpty(this)) this->first = this->last;
    else oldlast->next = this->last;
    this->n = this->n + 1;
    assert(RingBuffer_check(this));
}

Data RingBuffer_dequeue(RingBuffer *this) {
    if (RingBuffer_isEmpty(this)) {
        // throw error here?
        abort();
    }
    Data item = this->first->item;
    this->first = this->first->next;
    this->n -= 1;
    if (RingBuffer_isEmpty(this)) this->last = NULL;
    assert(RingBuffer_check(this));
    return item;
}

char *RingBuffer_toString(RingBuffer *this) {
    Node *current;
    size_t estSize = sizeof(char) * (this->n * 10);
    char *s = (char *) malloc(estSize);

    for (current = this->first; current != this->last; current = current->next) {
        char *tmp = Data_toString(current->item);
        size_t tmpSz = strlen(tmp);
        size_t currSz = strlen(s);
        if (estSize < tmpSz + currSz)
            realloc(s, tmpSz + currSz);
        strncat(s, tmp, tmpSz + currSz);
        free(tmp);
//        tmp = NULL;
    }
    return s;
}

// check internal invariants
bool RingBuffer_check(RingBuffer *this) {
    if (this->n < 0) {
        return false;
    } else if (this->n == 0) {
        if (this->first != NULL) return false;
        if (this->last != NULL) return false;
    } else if (this->n == 1) {
        if (this->first == NULL || this->last == NULL) return false;
        if (this->first != this->last) return false;
        if (this->first->next != NULL) return false;
    } else {
        if (this->first == NULL || this->last == NULL) return false;
        if (this->first == this->last) return false;
        if (this->first->next == NULL) return false;
        if (this->last->next != NULL) return false;

        // check internal consistency of instance variable n
        int numberOfNodes = 0;
        for (Node *x = this->first; x != NULL && numberOfNodes <= this->n; x = x->next) {
            numberOfNodes++;
        }
        if (numberOfNodes != this->n) return false;

        // check internal consistency of instance variable this->last
        Node *lastNode = this->first;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        if (this->last != lastNode) return false;
    }

    return true;
}


typedef struct ListIterator {
    RingBuffer *rb;
    Node *current;
} ListIterator;

void ListIterator_init(ListIterator *this, RingBuffer *target) {
    this->rb = target;
    this->current = this->rb->first;
}

bool ListIterator_hasNext(ListIterator *this) {
    return this->current != NULL;
}

Data ListIterator_next(ListIterator *this) {
    if (!ListIterator_hasNext(this)) {
        // how to handle this?
        abort();
    }
    Data item = this->current->item;
    this->current = this->current->next;
    return item;
}

//void remove() {
//    throw new UnsupportedOperationException();
//}

//public static void main(String[] args) {
//    LinkedQueue < String > queue = new
//    LinkedQueue<String>();
//    while (!StdIn.isEmpty()) {
//        String item = StdIn.readString();
//        if (!item.equals("-"))
//            queue.enqueue(item);
//        else if (!queue.isEmpty())
//            StdOut.print(queue.dequeue() + " ");
//    }
//    StdOut.println("(" + queue.size() + " left on queue)");
//}