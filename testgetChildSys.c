#include "types.h"
#include "stat.h"
#include "user.h"

int main() {
    fork();
    // wait();

    fork();
    // wait();

    fork();
    getchildren();
   
    while (wait() != -1) {}
    sleep(1);
    exit();
    return 0;
}
