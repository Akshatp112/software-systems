/*
24. Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid1 = fork();

    if (pid1 < 0) {
        perror("fork");
        return 1;
    } else if (pid1 == 0) {
        // First child
        printf("First child started. PID = %d\n", getpid());
        sleep(3);
        printf("First child exiting. PID = %d\n", getpid());
        exit(1);
    }

    pid_t pid2 = fork();

    if (pid2 < 0) {
        perror("fork");
        return 1;
    } else if (pid2 == 0) {
        // Second child
        printf("Second child started. PID = %d\n", getpid());
        sleep(5);
        printf("Second child exiting. PID = %d\n", getpid());
        exit(2);
    }

    pid_t pid3 = fork();

    if (pid3 < 0) {
        perror("fork");
        return 1;
    } else if (pid3 == 0) {
        // Third child
        printf("Third child started. PID = %d\n", getpid());
        sleep(8);
        printf("Third child exiting. PID = %d\n", getpid());
        exit(3);
    }

    // Parent process
    int status;
    printf("Parent waiting for first child: PID = %d\n", pid1);
    waitpid(pid1, &status, 0);  // Wait specifically for first child
    if (WIFEXITED(status))
        printf("First child exited with status %d\n", WEXITSTATUS(status));

    printf("Parent now waiting for second child: PID = %d\n", pid2);
    waitpid(pid2, &status, 0);  // Wait specifically for second child
    if (WIFEXITED(status))
        printf("Second child exited with status %d\n", WEXITSTATUS(status));
    
    printf("Parent now waiting for third child: PID = %d\n", pid3);
    waitpid(pid3, &status, 0);  // Wait specifically for third child
    if (WIFEXITED(status))
        printf("Third child exited with status %d\n", WEXITSTATUS(status));
    return 0;
}

/*

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/24$ gcc 24.c

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/24$ ./a.out
First child started. PID = 1649
Second child started. PID = 1650
Parent waiting for first child: PID = 1649
Third child started. PID = 1651
First child exiting. PID = 1649
First child exited with status 1
Parent now waiting for second child: PID = 1650
Second child exiting. PID = 1650
Second child exited with status 2
Parent now waiting for third child: PID = 1651
Third child exiting. PID = 1651
Third child exited with status 3

*/
