#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc <= 3)
        fprintf(stderr, "Usage: cmd_arg_csv <output_file> <records_per_line> record1 record2 ...\n");

    FILE* fp = fopen(argv[1], "w+");

    if (!fp) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    int i, rpl;

    rpl = atoi(argv[2]);

    for (i = 3; i < argc; i++) {
        if ((i - 2) % rpl == 0)
            fprintf(fp, "%s\n", argv[i]);
        else
            fprintf(fp, "%s,", argv[i]);
    }

    if (ferror(fp))
        puts("I/O error for file");

    fclose(fp);
    exit(0);
}