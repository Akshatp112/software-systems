/*
 26. Write a program to execute ls -Rl by the following system calls
 a. execl
 b. execlp
 c. execle
 d. execv
 e. execvp
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    printf("Parent PID = %d: Executing 'ls -Rl'\n", getpid());

    // Using execl
    printf("\n--- Using execl ---\n");
    if (fork() == 0) {
        execl("/bin/ls", "ls", "-Rl", NULL);
        perror("execl");  // If exec fails
        exit(1);
    }
    wait(NULL);

    // Using execlp
    printf("\n--- Using execlp ---\n");
    if (fork() == 0) {
        execlp("ls", "ls", "-Rl", NULL);
        perror("execlp");
        exit(1);
    }
    wait(NULL);

    // Using execv
    printf("\n--- Using execv ---\n");
    if (fork() == 0) {
        char *args[] = {"ls", "-Rl", NULL};
        execv("/bin/ls", args);
        perror("execv");
        exit(1);
    }
    wait(NULL);

    // Using execvp
    printf("\n--- Using execvp ---\n");
    if (fork() == 0) {
        char *args[] = {"ls", "-Rl", NULL};
        execvp("ls", args);
        perror("execvp");
        exit(1);
    }
    wait(NULL);

    return 0;
}

/*

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/26$ gcc 26.c
aksht@HP-Pavilion:~/software-systems/Hands-on list 1/26$ ./a.out
Parent PID = 1899: Executing 'ls -Rl'

--- Using execl ---
.:
total 24
-rw-r--r-- 1 aksht aksht  1147 Sep 22 11:16 26.c
-rwxr-xr-x 1 aksht aksht 16424 Sep 22 11:17 a.out

--- Using execlp ---
.:
total 24
-rw-r--r-- 1 aksht aksht  1147 Sep 22 11:16 26.c
-rwxr-xr-x 1 aksht aksht 16424 Sep 22 11:17 a.out

--- Using execv ---
.:
total 24
-rw-r--r-- 1 aksht aksht  1147 Sep 22 11:16 26.c
-rwxr-xr-x 1 aksht aksht 16424 Sep 22 11:17 a.out

--- Using execvp ---
.:
total 24
-rw-r--r-- 1 aksht aksht  1147 Sep 22 11:16 26.c
-rwxr-xr-x 1 aksht aksht 16424 Sep 22 11:17 a.out

*/
