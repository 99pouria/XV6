#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    int ppid = getpid();
    
    for (int i = 0; i < 10; i++) {
        if (getpid() == ppid) {
            fork();
        }
    }

    if (getpid() != ppid) {
        for (int i = 1; i <= 1000; i++) {
            printf(1, "/%d/ : /%d/\n\n", getpid(), i);
        }
    }

    while (wait() != -1) {}
    sleep(1);
    exit();
    return 0;
}
