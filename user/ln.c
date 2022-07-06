#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include <stddef.h>

extern int symlink(const char *oldpath, const char *newpath);

int
main(int argc, char *argv[])
{
    if((argc > 4) | (argc < 3)){
        fprintf(2,"Usage: ln old new\n");
        exit(1);
    }
    if(argc == 3){
        if(link(argv[1], argv[2]) < 0){
            fprintf(2, "link %s %s: failed\n", argv[1], argv[2]);
            exit(1);
        }
        exit(0);
    }
    
    else /*if(strcmp(argv[1], "-s") == 0)*/{
        //printf("symlink returns: %d\n", symlink(argv[2], argv[3]));
        if(symlink(argv[2], argv[3]) < 0){
            fprintf(2, "symlink %s %s: failed\n", argv[2], argv[3]);
        }
        exit(1);
    }
    exit(0);
    
    // if(argc != 3 && argc != 4){
    //     fprintf(2, "Usage: ln [command] old new\n");
    //     exit(1);
    // }

    // if(argc == 4){
    //     char s_command[] = "-s";
    //     int i = symlink(argv[2], argv[3]);
    //     printf("ln: i = %d\n", i);
    //     if(strcmp(argv[1], s_command) == 0){
    //         //if(symlink(argv[2], argv[3]) < 0)
    //             fprintf(2, "symlink %s %s: was failed\n", argv[2], argv[3]);
    //         exit(0);
    //     }
    //     else {
    //         fprintf(2, "commad %s: didn't found\n", argv[1]);
    //         exit(0);
    //     }
    // }

    // if(link(argv[1], argv[2]) < 0)
    //     fprintf(2, "link %s %s: failed\n", argv[1], argv[2]);
    // exit(0);
}

