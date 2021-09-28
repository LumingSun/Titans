#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFERSIZE 4096

int main(int argc, char* argv[]){
    if(argc!=3){
        printf("help: mycp src dst\n");
        return 1;
    }
    
    int srcfd = open(argv[1], O_RDONLY);
    int dstfd = open(argv[2], O_CREAT | O_WRONLY, 0666);

    char buffer[BUFFERSIZE] = {0};

    while(1){
        int content = read(srcfd, buffer, BUFFERSIZE);
        if(content<=0)
            break;
        else{
            write(dstfd, buffer, content);
        }
    }
    close(srcfd);
    close(dstfd);
    return 0;
}