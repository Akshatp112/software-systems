/*
22.. Write a program to create a Zombie state of the running program.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process exiting. PID = %d\n", getpid());
        exit(0); // Child exits immediately → becomes zombie
    } else {
        // Parent process sleeps to keep child zombie
        printf("Parent process sleeping. PID = %d\n", getpid());
        sleep(30); // Check zombie using `ps -l`
    }

    return 0;
}


/*
Terminal 1:

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/22$ gcc 22.c -o 22
aksht@HP-Pavilion:~/software-systems/Hands-on list 1/22$ ./22
Parent process sleeping. PID = 1460
Child process exiting. PID = 1461

Terminal 2:
aksht@HP-Pavilion:~/software-systems/Hands-on list 1/22$ ps -l | grep 22
aksht@HP-Pavilion:~/software-systems/Hands-on list 1/22$ ps -ef | grep 22
aksht       1460     363  0 10:48 pts/0    00:00:00 ./22
aksht       1461    1460  0 10:48 pts/0    00:00:00 [22] <defunct>
aksht       1479     906  0 10:48 pts/2    00:00:00 grep --color=auto 22

1460 -> parent
1461 -> child
1461 -> <defunct> -> ZOMBIE

*/
