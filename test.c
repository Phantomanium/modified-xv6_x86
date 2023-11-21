#include "types.h"
#include "user.h"
#include "date.h"

// long long busy_loop(long long limit)
// {
//     long long sum = 0;
//     for (long long i = 0; i < limit; i++)
//     {
//         sum += i;
//         // Not letting it overflow
//         if (sum > 1e10)
//             sum = 0;
//     }
//     return sum;
// }
// int main(int argc, char *argv[])
// {
//     if (argc != 2)
//     {
//         printf(1, "Usage: test <processCount>\n");
//         exit();
//     }
//     int processCount = atoi(argv[1]);
//     long long delay = 1e7;
//     // Create child processes do some computation (mimic it by sleep) and exit
//     for (int i = 0; i < processCount; i++)
//     {
//         printf(1, "I am Parent (Creating Process: %d)\n", i);
//         int pid = fork();
//         if (pid == 0)
//         {
//             printf(1, "I am Child %d Starting Processing\n", i);

//             //So the starting process takes the maxmimum time to finish
//             long long sum = busy_loop(delay * (processCount - i));
//             printf(1, "I am Child %d Finished Processing with calculating sum %d\n", i, sum);
//             exit();
//         }

//         // Different delays before starting processes
//         long long sum = busy_loop(delay * i);

//         // Just to make sure sum is not optimized out
//         printf(1, "%d - ", sum);
//     }

//     printf(1, "I am Parent Finished Processing\n");
//     // Waiting for all child processes to finish
//     for (int i = 0; i < processCount; i++)
//     {
//         wait();
//     }
//     exit();
// }



// int main(){
//     //Use the newly created system call to get the time of the day
//     struct rtcdate r;
//     gettimeoftheday(&r);
//     printf(1, "Time of the day is: %d:%d:%d\n", r.hour, r.minute, r.second);
//     exit();
// }
