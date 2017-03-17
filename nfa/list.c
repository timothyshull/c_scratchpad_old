
#include <stdlib.h>
#include <string.h>
#include "list.h"

void List_init(List *this, void (*destroy)(void *data)) {
    this->size = 0;
    this->destroy = destroy;
    this->head = NULL;
    this->tail = NULL;
    return;
}

void List_destroy(List *this) {
    void *data;

    while (List_size(this) > 0) {
        if (List_rem_next(this, NULL, (void **) &data) == 0 && this->destroy != NULL) {
            this->destroy(data);
        }
    }
    memset(this, 0, sizeof(List));
    return;
}

int List_ins_next(List *this, Node *element, const void *data) {
    Node *new_element;

    if ((new_element = (Node *) malloc(sizeof(Node))) == NULL) {
        return -1;
    }

    new_element->data = (void *) data;
    if (element == NULL) {

        if (List_size(this) == 0) {
            this->tail = new_element;
        }

        new_element->next = this->head;
        this->head = new_element;
    } else {

        if (element->next == NULL) {
            this->tail = new_element;
        }

        new_element->next = element->next;
        element->next = new_element;
    }

    this->size++;
    return 0;
}

int List_rem_next(List *this, Node *element, void **data) {
    Node *old_element;

    if (List_size(this) == 0) {
        return -1;
    }

    if (element == NULL) {
        *data = this->head->data;
        old_element = this->head;
        this->head = this->head->next;

        if (List_size(this) == 1) {
            this->tail = NULL;
        }

    } else {

        if (element->next == NULL) {
            return -1;
        }

        *data = element->next->data;
        old_element = element->next;
        element->next = element->next->next;

        if (element->next == NULL) {
            this->tail = element;
        }

    }

    free(old_element);
    this->size--;

    return 0;
}
