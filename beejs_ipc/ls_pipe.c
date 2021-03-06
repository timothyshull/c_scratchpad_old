#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int pfds[2];
    pipe(pfds);
    if (!fork()) {
        /* close normal stdout */
        /* make stdout same as pfds[1] */
        close(1);
        dup(pfds[1]);
        close(pfds[0]); /* we don't need this */
        execlp("ls", "ls", NULL);
    } else {
        close(0);       /* close normal stdin */
        dup(pfds[0]);   /* make stdin same as pfds[0] */
        close(pfds[1]); /* we don't need this */
        execlp("wc", "wc", "-l", NULL);
    }
    return 0;
}