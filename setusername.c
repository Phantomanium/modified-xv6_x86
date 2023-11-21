#include "types.h"
#include "user.h"
#include "fcntl.h"

#ifndef MAX_USERNAME_LENGTH
#define MAX_USERNAME_LENGTH 50
#endif


int main(int argc, char*argv[]){
    if(argc != 2){
        printf(1, "Usage: setusername <username>\n");
        exit();
    }
    char* username = argv[1];
    int fd = 1;
    fd = open("username", O_WRONLY | O_CREATE);
    if(fd < 0){
        printf(1, "Error1: Could not save username\n");
        exit();
    }

    int result = write(fd, username, strlen(username));
    //Empty the rest of file
    char buf[MAX_USERNAME_LENGTH];
    memset(buf, 0, MAX_USERNAME_LENGTH);
    write(fd, buf, MAX_USERNAME_LENGTH);
    if(result < 0){
        printf(1, "Error2: Could not save username\n");
        exit();
    }
    close(fd);
    //Set the username
    result = setusername(username);
    if(result == -1){
        printf(1, "Error3: Username is too long\n");
    }
    else{
        char buf[100];
        getusername(buf, 100);
        printf(1, "Username set to: %s\n", buf);
    }
    exit();
}