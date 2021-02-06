#include "types.h"
#include "stat.h"
#include "user.h"

int main() {
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
    int id1,i,q;
    id1=fork();
    // wait();
    if (id1<0){
        printf(0,"failed");
    }
    else if (id1 >0)//parent
    {
        setpriority(6);
        for(i=0;i<1000;i++)
            printf(0,"\n6");
    }
    else{
            q=setpriority(1);//make it low priority
            printf(1,"%d------------------------",q);
            for (i=0 ; i<1000;i++)
                printf(0,"\n 1");
    }
    while (wait() != -1) {}
    sleep(1);
    exit();
    return 0;
}
