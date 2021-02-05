#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    int ppid = getpid();
    if (fork() == 0) {
        printf(1, "we are in child proccess,\n"); 
        printf(1, "we know parent pid is %d,\n", ppid);
        printf(1, "parent pid with new syscal is: %d\n", getparentid());
    }

    while (wait() != -1) {}
    sleep(1);
    exit();
    return 0;
}
