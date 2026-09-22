/*
27. Write a program to get maximum and minimum real time priority.
*/

#include <stdio.h>
#include <sched.h>

int main() {
    int min_fifo = sched_get_priority_min(SCHED_FIFO);
    int max_fifo = sched_get_priority_max(SCHED_FIFO);

    int min_rr = sched_get_priority_min(SCHED_RR);
    int max_rr = sched_get_priority_max(SCHED_RR);

    printf("SCHED_FIFO: min priority = %d, max priority = %d\n", min_fifo, max_fifo);
    printf("SCHED_RR  : min priority = %d, max priority = %d\n", min_rr, max_rr);

    return 0;
}

/*

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/27$ gcc 27.c

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/27$ ./a.out
SCHED_FIFO: min priority = 1, max priority = 99
SCHED_RR  : min priority = 1, max priority = 99

*/
