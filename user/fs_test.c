#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"

#define BSIZE 1024  // block size
#define N 268*BSIZE

void
print_msg(int val, char* msg){
    if (val > 0){
        printf("SUCESS: %s\n", msg);
    }
    else {
        printf("FAILED: %s\n", msg);
    }
}

void write_file_size(int size){
    int fd;
    int i;

   char path[] = "file";
   char data[BSIZE];

    fd = open(path, O_CREATE | O_RDWR);
    print_msg(fd, "FILE OPEN");

    for(i = 0; i < size; i++){
        write(fd, data, sizeof(data));
        // printf("Writing block: %d\n", i);
    }
    close(fd);

    printf("SUCESS: FILE SIZE %d\n", size);

}

int
main(void)
{   
    // write_file_size(10); //12KB
    // write_file_size(268); //268KB
    // write_file_size(1000); //1MB
    write_file_size(10000); //10MB

    exit(0);

}

