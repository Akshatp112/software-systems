/*
19. Develop a program to initiate process in distinct states:
a. running
b. sleeping
c. stopped

Confirm the current state od the process using the relevant commands.
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Process started. PID = %d\n", getpid());

    while (1) {
        printf("Process is running...\n");

        // Keep CPU busy for a short time
        for (long i = 0; i < 500000000; i++);

        printf("Process is sleeping...\n");
        sleep(5);
    }

    return 0;
}


/*

Terminal 1:

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/19$ gcc 19.c -o 19

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/19$ ./19
Process started. PID = 2918
Process is running...
Process is sleeping...
Process is running...
Process is sleeping...
Process is running...
Process is sleeping...
Process is running...
Process is sleeping...
Process is running...
Process is sleeping...
Process is running...
^Z
[2]+  Stopped                    ./19


Terminal 2:

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/22$ ps -o pid,state,cmd -p 2918
    PID S CMD
   2918 R ./19

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/22$ ps -o pid,state,cmd -p 2918
    PID S CMD
   2918 S ./19

*/
