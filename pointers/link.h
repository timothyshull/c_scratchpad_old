#ifndef OPAQUE_PTRS_LINK_H
#define OPAQUE_PTRS_LINK_H

typedef void *Data;
typedef struct _linkedList LinkedList;
LinkedList* LinkedList_ctor();
void LinkedList_dtor(LinkedList *list);
void add_node(LinkedList *, Data);
Data remove_node(LinkedList *);

#endif //OPAQUE_PTRS_LINK_H
