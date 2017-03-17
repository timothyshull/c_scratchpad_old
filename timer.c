#include <stdio.h>
#include <time.h>
#include <unistd.h>

/*
 * count - number of loop iterations
 * original code from http://www.java2s.com/Code/C/Development/Testourtimerfunction.htm
 */
void timer(long count, char *(*read_func)(const char[]), const char input_file[]) {
    long i = 0; // loop counter
    time_t calendar = 0; // holds calendar time
    clock_t now = 0; // holds initial clock time
    unsigned long elapsed = 0; // elapsed clock time secs
    unsigned long total = 0; // total for each run combined

    for (i = 0L; i < count; i++) {
        sync();
        calendar = time(NULL); // get current calendar time
        now = clock();  // get current clock time
        printf("Initial clock time: %lu, initial calendar time: %lu\n", now, calendar);
        read_func(input_file);
        elapsed = (clock() - now) / CLOCKS_PER_SEC;
        total += elapsed;
        printf("\nElapsed: %ld seconds, iteration number: %ld", elapsed, i);
    }

    printf("\nCPU time for %ld iterations is %.2lf seconds\n", count, (double) (clock() - now) / CLOCKS_PER_SEC);
    printf("\nFinal clock time = %lu Final calendar time: %lu\n", clock(), time(NULL));
    printf("\nElapsed calendar time to execute the program is %lf\n", difftime(time(NULL), calendar));
    // add line to print total and average
}