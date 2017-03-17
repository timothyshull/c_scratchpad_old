//
// Created by Timothy Shull on 1/4/16.
//

//struct stat {
//    mode_t st_mode;  file type & mode (permissions)
//    ino_t st_ino;  i-node number (serial number)
//    dev_t st_dev;  device number (file system)
//    dev_t st_rdev;  device number for special files
//    link_t st_nlink;  number of links
//    uid_t st_uid;  user ID of owner
//    gid_t st_gid;  group id of owner
//    off_t st_size;  size in bytes for regular files
//    time_t st_atime;  time of last access
//    time_t st_mtime;  time of last modification
//    time_t st_ctime;  time of last file status change
//    blksize_t st_blksize;  best I/O block size
//    blkcnt_t st_blocks;  number of disk blocks allocated
//};

#include "4_3.h"
#include <stdlib.h>

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        print_file_type(argv[i]);
    }
    exit(0);
}