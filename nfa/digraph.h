#ifndef NFA_DIGRAPH_H
#define NFA_DIGRAPH_H

#include "list.h"

typedef struct Digraph_ {
    int _num_vertices;
    int _num_edges;
    List *_adjacency_list;
    int *_in_degree;
} Digraph;

void Digraph_init(Digraph *this);

void Digraph_construct(Digraph *this, int num_vertices);

void Digraph_copy_construct(Digraph *this, Digraph *g);

void Digraph_destroy(Digraph *this);

#define Digraph_num_vertices(this) ((this)->_num_vertices)

#define Digraph_num_edges(this) ((this)->_num_edges)

void Digraph_validate_vertex(Digraph *this, int v);

void Digraph_add_edge(Digraph *this, int v, int w);

List *Digraph_get_adjacent_vertices(Digraph *this, int v);

int Digraph_get_out_degree(Digraph *this, int v);

int Digraph_get_in_degree(Digraph *this, int v);

Digraph *Digraph_reverse(Digraph *this);

char *Digraph_to_string(Digraph *this);

int *Digraph_directed_dfs(Digraph *this); // returns an array of the marked vertices

#endif //NFA_DIGRAPH_H
