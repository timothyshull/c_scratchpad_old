#include <stdio.h>

#define MAXLINE 1000
#define LIMIT 80

int ngetline(char line[], int lim);

int main(void) {
    int len;
    char line[MAXLINE];

    while ((len = ngetline(line, MAXLINE)) > 0) {
        if (len > LIMIT)
            printf("%s", line);
    }

    return 0;
}

int ngetline(char s[], int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = (char) c;

    if (c == '\n') {
        s[i] = (char) c;
        ++i;
    }
    s[i] = '\0';

    return i;
}