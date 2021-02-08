#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    // int id1,id2,i,q;
    // id1=fork();
    // // wait();
    // if (id1<0){
    //     printf(0,"failed");
    // }
    // else if (id1 >0)//parent
    // {
    //     id2=fork();
    //     if (id2<0)
    //         printf(0,"failed");
    //     else if (id2>0){
    //         setpriority(3);//make it low priority
    //         for (i=0 ; i<10;i++)
    //             printf(1,"\n this is from paaaarent %d ...priority has  been set to 6",getpid());
    //     }
    //     else{
    //         setpriority(2);//make it low priority
    //         for (i=0 ; i<10;i++)
    //             printf(1,"\n this is from child 1 %d ...priority has  been set to 5",getpid());
    //     }
    // }
    // else{
    //         q=setpriority(1);//make it low priority
    //         printf(1,"%d------------------------",q);
    //         for (i=0 ; i<10;i++)
    //             printf(1,"\n this is from %d ...priority has  been set to 1",getpid());
    // }
    // while (wait() != -1) {}
    // sleep(1);
    // exit();
    // return 0;
    // int id1,i,q;
    // id1=fork();
    // // wait();
    // if (id1<0){
    //     printf(0,"failed");
    // }
    // else if (id1 >0)//parent
    // {
    //     setpriority(6);
    //     for(i=0;i<1000;i++)
    //         printf(0,"\n6");
    // }
    // else{
    //         q=setpriority(1);//make it low priority
    //         printf(1,"%d------------------------",q);
    //         for (i=0 ; i<1000;i++)
    //             printf(0,"\n 1");
    // }
    // while (wait() != -1) {}
    // sleep(1);
    // exit();
    // return 0;
    int parent = getpid();
    int i;

    for (i = 0; i < 6; i++)
    {
        if (getpid() == parent)
        {
            if (!fork()) //if it child
                setpriority(6);
        }
    }
    for (i = 0; i < 6; i++)
    {
        if (getpid() == parent)
        {
            if (!fork())
                setpriority(5);
        }
    }
    for (i = 0; i < 16; i++)
    {
        if (getpid() == parent)
            fork();
    }
    for (i = 0; i < 6; i++)
    {
        if (getpid() == parent)
        {
            if (!fork())
                setpriority(1);
        }
    }

    if (getpid() != parent)
    {
        for (i = 0; i < 250; i++)
        {
            printf(1, "/ChildNumber (%d) / : /%d/ \n", getpid(), i);
        }
    }
    else
    {
        int pidL[30];
        int cbtL[30];
        int ttL[30];
        int wtL[30];
        int tempCBT, tempTT, tempWT;
        int cbtavg = 0;
        int ttavg = 0;
        int wtavg = 0;
        for (i = 0; i < 30; i++)
        {
            pidL[i] = getCBT(&tempCBT, &tempTT, &tempWT);
            cbtL[i] = tempCBT;
            ttL[i] = tempTT;
            wtL[i] = tempWT;
            cbtavg += tempCBT;
            ttavg += tempTT;
            wtavg += tempWT;
        }
        for (i = 0; i < 30; i++)
        {
            printf(1, "CBT of %d is %d \n", pidL[i], cbtL[i]);
            printf(1, "TT of %d is %d \n", pidL[i], ttL[i]);
            printf(1, "WT of %d is %d \n", pidL[i], wtL[i]);
        }

        printf(1, "CBT AVG is %d", cbtavg / 30);
        printf(1, "TT AVG is %d", ttavg / 30);
        printf(1, "WT AVG is %d", wtavg / 30);
    }
}
