#include "types.h"
#include "user.h"

#ifndef MAX_USERNAME_LENGTH
#define MAX_USERNAME_LENGTH 50
#endif

int main(){
    //Use the newly created system call to get the time of the day
    char username[MAX_USERNAME_LENGTH];
    int result = getusername(username, MAX_USERNAME_LENGTH);
    if(!strcmp(username, "BSCS21027")){
        //Load the username from the file
        int fd = open("username", 0);
        if(fd > 0){
            char buf[MAX_USERNAME_LENGTH];
            int len = read(fd, buf, MAX_USERNAME_LENGTH);
            if(len > 0){
                setusername(buf);
                strcpy(username, buf);
            }
        }
        
    }
    
    if(result == -1){
        printf(1, "Error: Retrieving Username\n");
    }
    else{
        printf(1, "Username: %s\n", username);
    }
    exit();
}