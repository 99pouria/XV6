#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf(1, "Pass an argument as system call ID\n");
        exit();
        return 0;
    }

    int syscallID = atoi(argv[1]);

    getpid();
    getpid();
    getpid();
    getpid();

    printf(1, "syscall ID=%d, %d time(s) called!\n", syscallID, getSyscallCounter(syscallID));

    exit();
    return 0;
}
