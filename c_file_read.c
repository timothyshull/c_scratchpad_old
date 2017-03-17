#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

// see std::fread example for usage in C++
char *ffile_to_string(const char filename[]) {
    FILE *fp;
    fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "File open failure");
        perror(filename);
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    size_t size = (size_t) ftell(fp);
    rewind(fp);

    char *buffer = calloc(sizeof(char), size + 1);
    if (!buffer) {
        fclose(fp);
        fprintf(stderr, "String buffer memory allocation failed");
        exit(1);
    }

    if (1 != fread(buffer, size, 1, fp)) {
        fclose(fp);
        free(buffer);
        fprintf(stderr, "Unable to read the file %s into the buffer", filename);
        exit(1);
    }

    fclose(fp);
    *(buffer + size) = '\0'; // necessary?
    return buffer;
}


char *sfile_to_string(const char filename[]) {
    int fd;
    fd = open(filename, O_RDONLY, 0644);
    if (fd == -1) {
        fprintf(stderr, "File open failure");
        perror(filename);
        exit(1);
    }

    off_t size;

    size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET); // rewind

    char *buffer = calloc(sizeof(char), (size_t) (size + 1));
    if (!buffer) {
        close(fd);
        fprintf(stderr, "String buffer memory allocation failed");
        exit(1);
    }

    ssize_t nr;
    nr = read(fd, buffer, (size_t) size);
    // can also check that nr == size here
    if (nr == -1) {
        close(fd);
        free(buffer);
        fprintf(stderr, "Unable to read the file %s into the buffer", filename);
        exit(1);
    }

    close(fd);
    *(buffer + size) = '\0'; // necessary?
    return buffer;
}
