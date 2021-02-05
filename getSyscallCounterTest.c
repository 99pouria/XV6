#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    getpid();
    getpid();
    getpid();
    getpid();

    printf(1, "we called getpid syscall %d time(s)\n", getSyscallCounter(11));

    exit();
    return 0;
}
