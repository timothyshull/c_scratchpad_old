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
    fd = open("filename", O_WRONLY);
    fcntl(fd, F_SETLKW, &fl);  /* F_GETLK, F_SETLK, F_SETLKW */
}