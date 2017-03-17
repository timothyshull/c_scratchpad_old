#include <memory.h>
#include <stdlib.h>

char *global_header = "Chapter";
char global_array_header[] = "Chapter";

void display_header() {
    static char *static_header = "Chapter";
    char *local_header = "Chapter";
    static char static_array_header[] = "Chapter";
    char local_array_header[] = "Chapter";
    char *heap_header = (char *) malloc(8);
    strcpy(heap_header, "Chapter");

    strlen(static_header);
    strlen(local_header);
    strlen(static_array_header);
    strlen(local_array_header);
}

int main() {
    strlen(global_header);
    strlen(global_array_header);
    display_header();

    return 0;
}
