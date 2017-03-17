#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <sys/stat.h>
#include <stdbool.h>


int copy_file(char *input_filename, char *output_filename) {
    struct stat st_obj;

    FILE *input_file = fopen(input_filename, "r");
    if (!input_file) {
        static char error_message[50];
        sprintf(error_message, "Unable to open %s for reading. Exiting ...", input_filename);
        perror(error_message);
        exit(1);
    }

    FILE *output_file = fopen(output_filename, "w");
    if (!output_file) {
        static char error_message[50];
        sprintf(error_message, "Unable to create %s for writing. Exiting ...", output_filename);
        perror(error_message);
        exit(1);
    }

    // get the input file size
    if (fstat(input_file->_file, &st_obj) < 0) {
        perror("Unable to stat the input file. Exiting ...");
        exit(1);
    }

    // set the output file size
    if (ftruncate(output_file->_file, st_obj.st_size) < 0) {
        perror("Unable to set the output file size. Exiting ...");
        exit(1);
    }

    int character;
    for (;;) {
        character = fgetc(input_file);
        if (character == EOF) {
            break;
        }
        fputc(character, output_file);
    }

    int c;
    while ((c = fgetc(input_file)) != EOF) {
        fputc(c, output_file);
    }

    if (ferror(input_file) || ferror(output_file))
        printf("I/O error when reading.");
    else if (feof(input_file))
        puts("End of file reached successfully.");

    fclose(input_file);
    fclose(output_file);
    return 0;
}


int main(int argc, char **argv) {
//    int aflag = 0;
//    int bflag = 0;
//    char *cvalue = NULL;
    int index;
    int c;

    opterr = 0;

    static const struct option longopts[] = {
            {"input_file", required_argument, NULL, 'i'},
            {"output_file", required_argument, NULL, 'o'},
            {NULL, 0,                         NULL, 0}
    };

    char *input_file = NULL;
    char *output_file = NULL;
    while ((c = getopt_long(argc, argv, "i:o:", longopts, NULL)) != -1) {
        switch (c) {
            case 'i':
                if (optarg) {
                    input_file = (char *) malloc(strlen(optarg));
                    if (input_file == NULL) {
                        perror("Unable to allocate memory");
                        exit(1);
                    }
                    strcpy(input_file, optarg);
                }
                break;
            case 'o':
                if (optarg) {
                    output_file = (char *) malloc(strlen(optarg));
                    if (output_file == NULL) {
                        perror("Unable to allocate memory");
                        exit(1);
                    }
                    strcpy(output_file, optarg);
                }
                break;
            case '?':
                if (optopt == 'c')
                    fprintf(stderr, "Option -%c requires an argument.\n", optopt);
                else if (isprint(optopt))
                    fprintf(stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
                return 1;
            default:
                exit(1);
        }
    }

    bool bad_opts = false;
    for (index = optind; index < argc; index++) {
        printf("Non-option argument: %s\n", argv[index]);
        bad_opts = true;
    }

    if (bad_opts)
        exit(1);

    if (input_file != NULL && output_file != NULL) {
        int result = copy_file(input_file, output_file);
        if (result == 0)
            printf("Successfully copied all characters from input file to output file.");
    }

    return 0;
}
