#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

//void
//xfreopen(char const *filename, char const *mode, FILE *fp) {
//    if (!freopen(filename, mode, fp)) {
//        char const *f = (filename ? filename
//                                  : (fp == stdin ? _("stdin")
//                                                 : (fp == stdout ? _("stdout")
//                                                                 : (fp == stderr ? _("stderr")
//                                                                                 : _("unknown stream")))));
//        error(exit_failure, errno, _("failed to reopen %s with mode %s"),
//              quote_n(0, f), quote_n(1, mode));
//    }
//}


char *cp_getline(void) {
    const size_t size_increment = 10;
    char *buffer = malloc(size_increment);
    char *current_position = buffer;
    size_t maximum_length = size_increment;
    size_t length = 0;
    int character;
    if (current_position == NULL) { return NULL; }
    while (1) {
        character = fgetc(stdin);
        if (character == '\n') { break; }
        if (++length >= maximum_length) {
            char *new_buffer = realloc(buffer, maximum_length += size_increment);
            if (new_buffer == NULL) {
                free(buffer);
                return NULL;
            }
            current_position = new_buffer + (current_position - buffer);
            buffer = new_buffer;
        }
        *current_position++ = (char) character;
    }
    *current_position = '\0';
    return buffer;
}

char **read_to_array(int SIZE) {
    char **pArray = (char **) malloc(sizeof(char *) * SIZE);
    int i = 0;
    for (i = 0; i < SIZE; i++) {
        pArray[i] = strdup("a string");
    }
    return pArray;
}

void read_into_string(char *filename) {
    FILE *f = fopen(filename, "r");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);  //same as rewind(f);

    char *string = malloc((size_t) (fsize + 1));
    fread(string, (size_t) fsize, 1, f);
    fclose(f);

    string[fsize] = 0;
}


char **read_file(char *filename, int max_size) {
    FILE *fp;
    fp = fopen(filename, "r");

    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);  //same as rewind(f);


    char *line = NULL;
    size_t len = 0;
    ssize_t read;


    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu :\n", read);
        printf("%s", line);
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}

int main(int argc, char **argv) {
    int aflag = 0;
    int bflag = 0;
    char *cvalue = NULL;
    int index;
    int c;

    opterr = 0;

    static const struct option longopts[] = {
            {"animal",     required_argument, NULL, 'a'},
            {"brown-bear", required_argument, NULL, 'b'},
            {"cat",        required_argument, NULL, 'c'},
            {NULL, 0,                         NULL, 0}
    };


    while ((c = getopt_long(argc, argv, "a:b:c:", longopts, NULL)) != -1) {
        switch (c) {
            case 'a':
                if (optarg)
                    printf("a: %s\n", optarg);
                break;
            case 'b':
                if (optarg)
                    printf("b: %s\n", optarg);
                break;
            case 'c':
                if (optarg)
                    printf("c: %s\n", optarg);
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
                abort();
        }
    }

    for (index = optind; index < argc; index++)
        printf("Non-option argument %s\n", argv[index]);
    return 0;
}