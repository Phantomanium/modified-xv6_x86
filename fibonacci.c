#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf(1, "Usage: <number>\n");
        exit();
    }
    int n = atoi(argv[1]);
    if (n < 0)
    {
        printf(1, "Invalid Input\n");
        exit();
    }
    char arr[3] = "th";
    if (n % 10 == 1)
    {
        arr[0] = 's';
        arr[1] = 't';
    }
    else if (n % 10 == 2)
    {
        arr[0] = 'n';
        arr[1] = 'd';
    }
    else if (n % 10 == 3)
    {
        arr[0] = 'r';
        arr[1] = 'd';
    }
    if (n < 2)
    {
        printf(1, "The %d%s Fibonacci Number is: %d\n", n, arr, n);
        exit();
    }
    int a = 0, b = 1, c = 0;
    for (int i = 0; i < n - 1; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    printf(1, "The %d%s Fibonacci Number is: %d\n", n, arr, c);
    exit();
}