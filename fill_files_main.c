#include "fill_files.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: fill_files filename fill_text num_per_line num_lines\n");
    } else {
        fill_files(argv[1], argv[2], atoi(argv[3]), atoi(argv[4]));
    }
    exit(0);
}