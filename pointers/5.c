#include <memory.h>
#include <stdlib.h>
#include <stdio.h>

char *global_header = "Chapter";
char global_array_header[] = "Chapter";

void display_header() {
    static char *static_header = "Chapter";
    char *local_header = "Chapter";
    static char static_array_header[] = "Chapter";
    char local_array_header[] = "Chapter";
    char *heap_header = (char *) malloc(8);
    strcpy(heap_header, "Chapter");
}

int main() {
    // string declaration
    char header[32];
    // header = "Media Player"; -> not assignable
    strcpy(header, "Media Player");
    printf("header: %s\n", header);

    char *headerp;
    // strcpy(headerp, "Media Player"); -> local variable not initialized
    headerp = "Media Player";
    printf("headerp: %s\n", headerp);

    // initialization
    char headeri[] = "Media Player";
    // or
    char headericp[13];
    strcpy(headericp, "Media Player");
    // or
    char headerslo[] = {'M', 'e', 'd', 'i', 'a', ' ', 'P', 'l', 'a', 'y', 'e', 'r', '\0'};

    // using malloc
    char *headerm1 = (char *) malloc(strlen("Media Player") + 1);
    strcpy(headerm1, "Media Player");
    // or
    char *headerm2 = (char *) malloc(13);
    strcpy(headerm2, "Media Player");

    printf("headeri: %s\n", headeri);
    printf("headericp: %s\n", headericp);
    printf("headerslo: %s\n", headerslo);
    printf("headerm1: %s\n", headerm1);
    printf("headerm2: %s\n", headerm2);

    return 0;
}