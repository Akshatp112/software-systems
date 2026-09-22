/*
29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
*/

#include <stdio.h>
#include <unistd.h>
#include <sched.h>

int main() {
    pid_t pid = getpid();

    // Get current scheduling policy
    int policy = sched_getscheduler(pid);
    if (policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }

    printf("Current scheduling policy of PID %d: ", pid);
    if (policy == SCHED_OTHER) printf("SCHED_OTHER\n");
    else if (policy == SCHED_FIFO) printf("SCHED_FIFO\n");
    else if (policy == SCHED_RR) printf("SCHED_RR\n");
    else printf("Unknown\n");

    // Set new scheduling policy (SCHED_RR) with priority 10
    struct sched_param param;
    param.sched_priority = 10;
    if (sched_setscheduler(pid, SCHED_RR, &param) == -1) {
        perror("sched_setscheduler");
    } else {
        printf("Scheduling policy changed to SCHED_RR with priority 10\n");
    }

    // Get updated scheduling policy
    policy = sched_getscheduler(pid);
    printf("Updated scheduling policy of PID %d: ", pid);
    if (policy == SCHED_OTHER) printf("SCHED_OTHER\n");
    else if (policy == SCHED_FIFO) printf("SCHED_FIFO\n");
    else if (policy == SCHED_RR) printf("SCHED_RR\n");
    else printf("Unknown\n");

    return 0;
}

/*

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/29$ gcc 29.c

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/29$ ./a.out
Current scheduling policy of PID 2476: SCHED_OTHER
sched_setscheduler: Operation not permitted
Updated scheduling policy of PID 2476: SCHED_OTHER

*/
