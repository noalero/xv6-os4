#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"

int main(int argc, char** argv){
    if(argc != 3){
        fprintf(2, "Usage: symlink_test oldpath newpath\n");
        exit(-1);
    }
    char buf[MAXPATH];
    printf("oldpath: %s\n", argv[1]);
    printf("newpath: %s\n", argv[2]);
    symlink(argv[1], argv[2]);
    printf("symlink has been created!\n");
    readlink(argv[2], buf, MAXPATH);
    printf("symlink content: %s\n", buf);
    exit(0);
}