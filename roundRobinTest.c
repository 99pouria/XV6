#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    changepolicy(1);
    int ppid = getpid();
    int CBTav = 0, TTav = 0, WTav = 0;
    int *CBTarr = malloc(10 * sizeof(int)); 
    int *TTarr = malloc(10 * sizeof(int));
    int *WTarr = malloc(10 * sizeof(int));
    int *PIDarr = malloc(10 * sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        if (getpid() == ppid)
        {
            fork();
        }
    }

    if (getpid() != ppid)
    {
        for (int i = 1; i <= 100; i++)
        {
            printf(1, "/%d/ : /%d/\n\n", getpid(), i);
        }
    }
    else
    {
        int cbt = 0, tt = 0, wt = 0;
        for (int i = 0; i < 10; i++)
        {
            PIDarr[i] = getCBT(&cbt, &tt, &wt);
            CBTarr[i] = cbt;
            TTarr[i] = tt;
            WTarr[i] = wt;
        }
        for (int i = 0; i < 10; i++)
        {
            printf(1, "PID: %d\n", PIDarr[i]);
            printf(1, "CPU burst time: %d\n", CBTarr[i]);
            printf(1, "Turnaround time: %d\n", TTarr[i]);
            printf(1, "Waiting Time: %d\n\n\n\n", WTarr[i]);
            CBTav += CBTarr[i];
            TTav += TTarr[i];
            WTav += WTarr[i];
        }
        printf(1, "CPU burst time average: %d\n", CBTav / 10);
        printf(1, "Turnaround time average: %d\n", TTav / 10);
        printf(1, "Waiting time average: %d\n", WTav / 10);
    }

    while (wait() != -1)
    {
    }
    sleep(1);
    exit();
    return 0;
}
