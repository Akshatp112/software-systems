/*
25. Write a program to execute an executable program.
 a. use some executable program
 b. pass some input to an executable program(for example execute an executable of $./a.out name)
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    printf("Parent PID = %d: Executing hello program\n", getpid());

    execl("./hello", "hello", "Akshat", NULL);

    // If execlp returns, it must have failed
    perror("execlp");
    return 1;
}

/*

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/25$ gcc hello.c -o hello

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/25$ gcc 25.c

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/25$ ./a.out
Parent PID = 1819: Executing hello program
Hello, Akshat!

*/
