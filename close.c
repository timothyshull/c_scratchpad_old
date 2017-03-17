#include <fcntl.h>
#include <sys/errno.h>
#include <stdio.h>


int main() {
    // requires absolute path because build is in a tmp directory
    const char fname[] = "/Users/skull/Programming/C/linux_system_programming/ch2/open.txt";
    int fd = open(fname, O_RDONLY, 0755);
    if (fd == -1) {
        // NOTE: these errors come from the Linux manpage - different for OSX
        // Some are only appropriate for certain file types
        // see man 2 open for more
        switch (errno) {
            case EACCES:
                /* The requested access to the file is not allowed, or search
                permission is denied for one of the directories in the path
                prefix of pathname, or the file did not exist yet and write
                access to the parent directory is not allowed. */
                perror("The \"open\" call returned an \"EACCES\" error.");
            case EDQUOT:
                /* Where O_CREAT is specified, the file does not exist, and the
                user's quota of disk blocks or inodes on the filesystem has
                been exhausted. */
                perror("The \"open\" call returned an \"EDQUOT\" error.");
            case EEXIST:
                /* pathname already exists and O_CREAT and O_EXCL were used. */
                perror("The \"open\" call returned an \"EEXIST\" error.");
            case EFAULT:
                /* pathname points outside your accessible address space. */
                perror("The \"open\" call returned an \"EFAULT\" error.");
            case EFBIG:
                /* See EOVERFLOW */
                perror("The \"open\" call returned an \"EFBIG\" error.");
            case EINTR:
                /* While blocked waiting to complete an open of a slow device
                (e.g., a FIFO; see fifo(7)), the call was interrupted by a
                signal handler; see signal(7). */
                perror("The \"open\" call returned an \"EINTR\" error.");
            case EINVAL:
                /* The filesystem does not support the O_DIRECT flag.  See NOTES
              for more information.

                 Invalid value in flags.

                 O_TMPFILE was specified in flags, but neither O_WRONLY nor
              O_RDWR was specified.
                 */
                perror("The \"open\" call returned an \"EINVAL\" error.");
            case EISDIR:
                /* pathname refers to a directory and the access requested
              involved writing (that is, O_WRONLY or O_RDWR is set).

                 pathname refers to an existing directory, O_TMPFILE and one of
              O_WRONLY or O_RDWR were specified in flags, but this kernel
              version does not provide the O_TMPFILE functionality.
                 */
                perror("The \"open\" call returned an \"EISDIR\" error.");
            case ELOOP:
                perror("The \"open\" call returned an \"ELOOP\" error.");
            case EMFILE:
                perror("The \"open\" call returned an \"EMFILE\" error.");
            case ENAMETOOLONG:
                perror("The \"open\" call returned an \"ENAMETOOLONG\" error.");
            case ENFILE:
                perror("The \"open\" call returned an \"ENFILE\" error.");
            case ENODEV:
                perror("The \"open\" call returned an \"ENODEV\" error.");
            case ENOENT:
                perror("The \"open\" call returned an \"ENOENT\" error.");
            case ENOMEM:
                perror("The \"open\" call returned an \"ENOMEM\" error.");
            case ENOSPC:
                perror("The \"open\" call returned an \"ENOSPC\" error.");
            case ENOTDIR:
                perror("The \"open\" call returned an \"ENOTDIR\" error.");
            case ENXIO:
                perror("The \"open\" call returned an \"ENXIO\" error.");
            case EOPNOTSUPP:
                perror("The \"open\" call returned an \"EOPNOTSUPP\" error.");
            case EOVERFLOW:
                perror("The \"open\" call returned an \"EOVERFLOW\" error.");
            case EPERM:
                perror("The \"open\" call returned an \"EPERM\" error.");
            case EROFS:
                perror("The \"open\" call returned an \"EROFS\" error.");
            case ETXTBSY:
                perror("The \"open\" call returned an \"ETXTBSY\" error.");
            case EWOULDBLOCK:
                perror("The \"open\" call returned an \"EWOULDBLOCK\" error.");
            case EBADF:
                perror("The \"open\" call returned an \"EBADF\" error.");
            default:
                perror("The \"open\" call returned an unrecognized error.");
        }
    } else {
        fprintf(stdout, "Successfully opened: \"%s\"", fname);
    }
    return 0;
}