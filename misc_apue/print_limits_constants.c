#include "apue.h"
#include <limits.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
    // ISO C integral values
    if (CHAR_BIT)
        printf("%d\n", CHAR_BIT);
    if (CHAR_MAX)
        printf("%d\n", CHAR_MAX);
    if (CHAR_MIN)
        printf("%d\n", CHAR_MIN);
    if (SCHAR_MAX)
        printf("%d\n", SCHAR_MAX);
    if (SCHAR_MIN)
        printf("%d\n", SCHAR_MIN);
    if (UCHAR_MAX)
        printf("%d\n", UCHAR_MAX);
    if (INT_MAX)
        printf("%d\n", INT_MAX);
    if (INT_MIN)
        printf("%d\n", INT_MIN);
    if (UINT_MAX)
        printf("%d\n", UINT_MAX);
    if (SHRT_MIN)
        printf("%d\n", SHRT_MIN);
    if (SHRT_MAX)
        printf("%d\n", SHRT_MAX);
    if (USHRT_MAX)
        printf("%d\n", USHRT_MAX);
    if (LONG_MAX)
        printf("%ld\n", LONG_MAX);
    if (LONG_MIN)
        printf("%ld\n", LONG_MIN);
    if (ULONG_MAX)
        printf("%lu\n", ULONG_MAX);
    if (LLONG_MAX)
        printf("%lld\n", LLONG_MAX);
    if (LLONG_MIN)
        printf("%lld\n", LLONG_MIN);
    if (ULLONG_MAX)
        printf("%llu\n", ULLONG_MAX);
    if (MB_LEN_MAX)
        printf("%d\n", MB_LEN_MAX);

    // ISO platform limits
    if (FOPEN_MAX)
        printf("%d\n", FOPEN_MAX);
    if (TMP_MAX)
        printf("%d\n", TMP_MAX);

    // POSIX limits
    if (_POSIX_ARG_MAX)
        printf("%d\n", _POSIX_ARG_MAX);
    if (_POSIX_CHILD_MAX)
        printf("%d\n", _POSIX_CHILD_MAX);
    if (_POSIX_HOST_NAME_MAX)
        printf("%d\n", _POSIX_HOST_NAME_MAX);
    if (_POSIX_LINK_MAX)
        printf("%d\n", _POSIX_LINK_MAX);
    if (_POSIX_LOGIN_NAME_MAX)
        printf("%d\n", _POSIX_LOGIN_NAME_MAX);
    if (_POSIX_MAX_CANON)
        printf("%d\n", _POSIX_MAX_CANON);
    if (_POSIX_MAX_INPUT)
        printf("%d\n", _POSIX_MAX_INPUT);
    if (_POSIX_NAME_MAX)
        printf("%d\n", _POSIX_NAME_MAX);
    if (_POSIX_NGROUPS_MAX)
        printf("%d\n", _POSIX_NGROUPS_MAX);
    if (_POSIX_OPEN_MAX)
        printf("%d\n", _POSIX_OPEN_MAX);
    if (_POSIX_PATH_MAX)
        printf("%d\n", _POSIX_PATH_MAX);
    if (_POSIX_PIPE_BUF)
        printf("%d\n", _POSIX_PIPE_BUF);
    if (_POSIX_RE_DUP_MAX)
        printf("%d\n", _POSIX_RE_DUP_MAX);
    if (_POSIX_SSIZE_MAX)
        printf("%d\n", _POSIX_SSIZE_MAX);
    if (_POSIX_STREAM_MAX)
        printf("%d\n", _POSIX_STREAM_MAX);
    if (_POSIX_SYMLINK_MAX)
        printf("%d\n", _POSIX_SYMLINK_MAX);
    if (_POSIX_SYMLOOP_MAX)
        printf("%d\n", _POSIX_SYMLOOP_MAX);
    if (_POSIX_TTY_NAME_MAX)
        printf("%d\n", _POSIX_TTY_NAME_MAX);
    if (_POSIX_TZNAME_MAX)
        printf("%d\n", _POSIX_TZNAME_MAX);

    return 0;
}