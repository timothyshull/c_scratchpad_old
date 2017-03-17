#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gc.h>

struct node {
    struct node *next;
    int dummy_payload;
};

static const double loop_seconds = 17.0;
static const int list_length = (2 * 1024 * 1024) / sizeof(struct node);

/* Make a new list of 'length' nodes.  'alloc' should be
 * &malloc or &GC_malloc. */
static struct node *MakeList(int length, void *(*alloc)(size_t)) {
    struct node *lst = NULL, *tmp;

    while (length-- > 0) {
        tmp = (struct node *) (*alloc)(sizeof *tmp);
        tmp->next = lst;
        lst = tmp;
    }
    return lst;
}

/* Explicitly free the nodes in the list. */
static void FreeList(struct node *lst) {
    while (lst != NULL) {
        struct node *tmp = lst->next;
        free(lst);
        lst = tmp;
    }
}

/* Pretend to free the list, but do nothing.  Rely on garbage
 * collection to free the list. */
static void
IgnoreList(struct node *lst) {
}

static unsigned long Loop(void *(*alloc)(size_t), void (*free_list)(struct node *)) {
    unsigned long count = 0;
    time_t start, now;

    time(&start);
    do {
        ++count;
        (*free_list)(MakeList(list_length, alloc));
        time(&now);
    } while (difftime(now, start) < loop_seconds);
    return count;
}

static double Print(char name[], void *(*alloc)(size_t),
      void (*free_list)(struct node *), double base) {
    time_t start, end;
    unsigned long count;
    double duration, rate, relative;

    time(&start);
    count = Loop(alloc, free_list);
    time(&end);
    duration = difftime(end, start);
    rate = count / duration;
    relative = base == 0.0 ? 1.0 : rate / base;
    printf("%10s  %9lu  %9.2e  %9.2e  %9.2f\n", name, count, duration, rate, relative);
    return rate;
}

int main() {
    double malloc_rate;

    printf("%10s  %9s  %9s  %9s  %9s\n", "name", "count", "duration",
           "rate", "relative");
    malloc_rate = Print("malloc", &malloc, &FreeList, 0.0);
    Print("Boehm", &GC_malloc, &IgnoreList, malloc_rate);
    return 0;
}
