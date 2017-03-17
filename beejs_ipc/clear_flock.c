#include <fcntl.h>
#include <unistd.h>

int main()
{
    struct flock fl;
    int fd;
    fl.l_type = F_WRLCK;  /* F_RDLCK, F_WRLCK, F_UNLCK    */
    fl.l_whence = SEEK_SET; /* SEEK_SET, SEEK_CUR, SEEK_END */
    fl.l_start = 0;        /* Offset from l_whence         */
    fl.l_len = 0;        /* length, 0 = to EOF           */
    fl.l_pid = getpid(); /* our PID                      */
    fd = open("filename", O_WRONLY); /* get the file descriptor */
    fcntl(fd, F_SETLKW, &fl); /* set the lock, waiting if necessary */
    fl.l_type = F_UNLCK; /* tell it to unlock the region */
    fcntl(fd, F_SETLK, &fl); /* set the region to unlocked */
}