#include "apue.h"
#include <dirent.h>
#include <limits.h>

/* function type that is called for each filename */
typedef int Myfunc(const char*, const struct stat*, int);

static Myfunc myfunc;

static int myftw(char*, Myfunc*);

static int dopath(Myfunc*);

static long nreg, ndir, nblk, nchr, nfifo, nslink, nsock, ntot;

int main(int argc, char* argv[]) {
    int ret;

    if (argc != 2)
        fprintf(stderr, "usage:  ftw  <starting-pathname>");

    ret = myftw(argv[1], myfunc);

    ntot = nreg + ndir + nblk + nchr + nfifo + nslink + nsock;

    if (ntot == 0)
        ntot = 1;
    printf("regular files  = %7ld, %5.2f %%\n", nreg, nreg * 100.0 / ntot);
    printf("directories    = %7ld, %5.2f %%\n", ndir, ndir * 100.0 / ntot);
    printf("block special  = %7ld, %5.2f %%\n", nblk, nblk * 100.0 / ntot);
    printf("char special   = %7ld, %5.2f %%\n", nchr, nchr * 100.0 / ntot);
    printf("FIFOs          = %7ld, %5.2f %%\n", nfifo, nfifo * 100.0 / ntot);
    printf("symbolic links = %7ld, %5.2f %%\n", nslink, nslink * 100.0 / ntot);
    printf("sockets        = %7ld, %5.2f %%\n", nsock, nsock * 100.0 / ntot);
    exit(ret);
}

#define    FTW_F    1
#define    FTW_D    2
#define    FTW_DNR    3
#define    FTW_NS    4

static char* fullpath;
static size_t pathlen;

static int myftw(char* pathname, Myfunc* func) {
    fullpath = path_alloc(&pathlen);
    if (pathlen <= strlen(pathname)) {
        pathlen = strlen(pathname) * 2;
        if ((fullpath = realloc(fullpath, pathlen)) == NULL)
            fprintf(stderr, "realloc failed");
    }
    strcpy(fullpath, pathname);
    return (dopath(func));
}

static int dopath(Myfunc* func) {
    struct stat statbuf;
    struct dirent* dirp;
    DIR* dp;
    int ret, n;

    if (lstat(fullpath, &statbuf) < 0)    /* stat error */
        return (func(fullpath, &statbuf, FTW_NS));
    if (S_ISDIR(statbuf.st_mode) == 0)    /* not a directory */
        return (func(fullpath, &statbuf, FTW_F));

    if ((ret = func(fullpath, &statbuf, FTW_D)) != 0)
        return (ret);

    n = (int) strlen(fullpath);
    if (n + NAME_MAX + 2 > pathlen) {    /* expand path buffer */
        pathlen *= 2;
        if ((fullpath = realloc(fullpath, pathlen)) == NULL)
            fprintf(stderr, "realloc failed");
    }
    fullpath[n++] = '/';
    fullpath[n] = 0;

    if ((dp = opendir(fullpath)) == NULL)    /* can't read directory */
        return (func(fullpath, &statbuf, FTW_DNR));

    while ((dirp = readdir(dp)) != NULL) {
        if (strcmp(dirp->d_name, ".") == 0 ||
            strcmp(dirp->d_name, "..") == 0)
            continue;        /* ignore dot and dot-dot */
        strcpy(&fullpath[n], dirp->d_name);    /* append name after "/" */
        if ((ret = dopath(func)) != 0)        /* recursive */
            break;    /* time to leave */
    }
    fullpath[n - 1] = 0;    /* erase everything from slash onward */

    if (closedir(dp) < 0)
        fprintf(stderr, "can't close directory %s", fullpath);
    return (ret);
}

static int myfunc(const char* pathname, const struct stat* statptr, int type) {
    switch (type) {
        case FTW_F:
            switch (statptr->st_mode & S_IFMT) {
                case S_IFREG:
                    nreg++;
                    break;
                case S_IFBLK:
                    nblk++;
                    break;
                case S_IFCHR:
                    nchr++;
                    break;
                case S_IFIFO:
                    nfifo++;
                    break;
                case S_IFLNK:
                    nslink++;
                    break;
                case S_IFSOCK:
                    nsock++;
                    break;
                case S_IFDIR:    /* directories should have type = FTW_D */
                    fprintf(stderr, "for S_IFDIR for %s", pathname);
            }
            break;
        case FTW_D:
            ndir++;
            break;
        case FTW_DNR:
            fprintf(stderr, "can't read directory %s", pathname);
            break;
        case FTW_NS:
            fprintf(stderr, "stat error for %s", pathname);
            break;
        default:
            fprintf(stderr, "unknown type %d for pathname %s", type, pathname);
    }
    return (0);
}
