/*
23. Write a program to create an orphan process
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
        printf("Child process started. PID = %d, Parent PID = %d\n", getpid(), getppid());
        sleep(10);  // Give time to parent to exit
        printf("Child after parent exit. PID = %d, Parent PID = %d\n", getpid(), getppid());
        exit(0);
    } else {
        // Parent process
        printf("Parent process exiting. PID = %d\n", getpid());
        exit(0);   // Parent exits immediately → child becomes orphan
    }

    return 0;
}

/*

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/23$ gcc 23.c

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/23$ ./a.out
Parent process exiting. PID = 1564
Child process started. PID = 1565, Parent PID = 1564

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/23$ Child after parent exit. PID = 1565, Parent PID = 359

*/
