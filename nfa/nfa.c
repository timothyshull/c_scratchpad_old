#include <stddef.h>
#include <memory.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "nfa.h"
#include "digraph.h"

#define BAD_REGEXP -2

void NFA_init(NFA *this) {
    this->_graph = NULL;
    this->_regexp = NULL;
    this->_m = 0;
}

void NFA_construct(NFA *this, const char regexp[]) {
    this->_m = (size_t) strlen(regexp);
    this->_regexp = (char *)malloc(this->_m + 1);
    strcpy(this->_regexp, regexp);

    Stack *ops = (Stack *)malloc(sizeof(Stack));
    Stack_init(ops);

    this->_graph = (Digraph *)malloc(sizeof(Digraph));
    Digraph_init(this->_graph);
    Digraph_construct(this->_graph, (int) this->_m + 1);

    for (int i = 0; i < this->_m; i++) {
        int lp = i;
        if (*(this->_regexp + i) == '(' || *(this->_regexp + i) == '|') {
            Stack_push(ops, i);
        } else if (*(this->_regexp + i) == ')') {
            int or = Stack_pop(ops); // will need to change this to handle void * to int

            if (*(this->_regexp + i) == '|') {
                lp = Stack_pop(ops);
                Graph_add_edge(this->_graph, lp, or + 1);
                Graph_add_edge(this->_graph, or, i);
            } else if (*(this->_regexp + i) == ')') {
                lp = or;
            } else {
                assert(0);
            }
        }

        if (i < this->_m - 1 && *(this->_regexp + i) == '*') {
            Graph_add_edge(this->_graph, lp, i + 1);
            Graph_add_edge(this->_graph, i + 1, lp);
        }

        if (*(this->_regexp + i) == '(' || *(this->_regexp + i) == '*' || *(this->_regexp + i) == ')') {
            Graph_add_edge(this->_graph, i, i + 1);
        }
    }

    if (Stack_size(ops) != 0) {
        fprintf(stderr, "Invalid regular expression");
        exit(BAD_REGEXP);
    }
}

void NFA_destroy(NFA *this) {
    if (this->_graph != NULL) {
        free(this->_graph);
    }
    if (this->_regexp != NULL) {
        free(this->_regexp);
    }
    this->_m = 0;
};

int NFA_recognizes(NFA *this, const char txt[]) {

};