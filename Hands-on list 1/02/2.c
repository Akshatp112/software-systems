/*
2. Write a simple program to execute in an infinite loop at the background.
 Go to /proc directory and identify all the process related information in the corresponding proc directory.
*/



#include <stdio.h>
#include <unistd.h>

int main() {
    while(1) {
        printf("Running process with PID: %d\n", getpid());
        sleep(20);   // sleep to avoid flooding the terminal
    }
    return 0;
}

/*
aksht@HP-Pavilion:~/software-systems/Hands-on list 1/02$ gcc 2.c -o 2

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/02$ ./2 &
[1] 1377
Running process with PID: 1377

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/02$ ps
    PID TTY          TIME CMD
    382 pts/0    00:00:00 bash
    1377pts/0    00:00:00 2
   1003 pts/0    00:00:00 ps

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/02$ cat /proc/1377/status

Name:   2
Umask:  0022
State:  S (sleeping)
Tgid:   1377
Ngid:	0
Pid:    1377
PPid:   382

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/02$ kill 992
[1]+  Terminated                 ./2

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/02$ ps
    PID TTY          TIME CMD
    382 pts/0    00:00:00 bash
   1037 pts/0    00:00:00 ps

*/
