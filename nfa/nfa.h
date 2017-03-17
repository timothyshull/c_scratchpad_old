#ifndef NFA_NFA_H
#define NFA_NFA_H

extern typedef struct Digraph_ {} Digraph;

typedef struct NFA_ {
    Digraph *_graph;
    char *_regexp;
    size_t _m;
} NFA;

void NFA_init(NFA *this);

void NFA_construct(NFA *this, const char regexp[]);

void NFA_destroy(NFA *this);

int NFA_recognizes(NFA *this, const char txt[]);

#endif //NFA_NFA_H
