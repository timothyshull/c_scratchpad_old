#ifndef NFA_LIST_H
#define NFA_LIST_H

typedef struct Node_ {
    void *data;
    struct Node_ *next;
} Node;

typedef struct List_ {
    int size;

    int (*match)(const void *key1, const void *key2);

    void (*destroy)(void *data);

    Node *head;
    Node *tail;
} List;

void List_init(List *this, void (*destroy)(void *data));

void List_destroy(List *this);

int List_ins_next(List *this, Node *element, const void *data);

int List_rem_next(List *this, Node *element, void **data);

#define List_size(this) ((this)->size)
#define List_head(this) ((this)->head)
#define List_tail(this) ((this)->tail)
#define List_is_head(this, element) ((element) == (this)->head ? 1 : 0)
#define List_is_tail(element) ((element)->next == NULL ? 1 : 0)
#define List_data(element) ((element)->data)
#define List_next(element) ((element)->next)

#endif //NFA_LIST_H
