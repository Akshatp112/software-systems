/*
20. Write a program, call fork and print the parent and child process id.
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else {
        // Parent process
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}

/*

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/20$ gcc 20.c

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/20$ ./a.out
Parent process: PID = 723, Child PID = 724
Child process: PID = 724, Parent PID = 723

*/
