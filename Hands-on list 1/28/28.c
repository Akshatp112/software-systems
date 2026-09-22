/*
28. Find out the priority of your running program. Modify the priority with nice command.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    pid_t pid = getpid();

    // Get current nice value
    int priority = getpriority(PRIO_PROCESS, pid);
    printf("Current priority of process %d: %d\n", pid, priority);

    // Increase nice value by 5 (lower priority)
    if (nice(5) == -1) perror("nice");

    // Get new priority
    priority = getpriority(PRIO_PROCESS, pid);
    printf("New priority of process %d: %d\n", pid, priority);

    return 0;
}

/*

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/28$ gcc 28.c

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/28$ ./a.out
Current priority of process 2338: 0
New priority of process 2338: 5

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/28$ ps -l
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
4 S  1000     363     359  0  80   0 -  1598 do_wai pts/0    00:00:00 bash
0 R  1000    2350     363  0  80   0 -  1798 -      pts/0    00:00:00 ps

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/28$ renice -n 5 -p 363
363 (process ID) old priority 0, new priority 5

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/28$ ps -l
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
4 S  1000     363     359  0  85   5 -  1598 do_wai pts/0    00:00:00 bash
0 R  1000    2375     363  0  85   5 -  1798 -      pts/0    00:00:00 ps

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/28$ ./a.out
Current priority of process 2386: 5
New priority of process 2386: 10

*/
