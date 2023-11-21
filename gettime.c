#include "types.h"
#include "user.h"
#include "date.h"

int main(){

    struct rtcdate r;
    int result = gettimeoftheday(&r);
    if(result == -1){
        printf(1, "Error: gettime failed\n");
    }
    else{
        printf(1, "Time: %d:%d:%d\n", r.hour, r.minute, r.second);
    }
    exit();
}