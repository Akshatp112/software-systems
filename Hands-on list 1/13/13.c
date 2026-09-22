/*
13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set readfds;
    struct timeval timeout;
    int ret;
    char buffer[100];

    // Initialize fd set
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    // Set timeout to 10 seconds
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("You have 10 seconds to type something:\n");

    // Wait for input
    ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (ret == -1) {
        perror("select");
	return 1;
    } 
    if (ret == 0) {
        printf("No input after 10 seconds.\n");
    }
    else {
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            read(STDIN_FILENO, buffer, sizeof(buffer));
            printf("You typed: %s", buffer);
        }
    }

    return 0;
}

/*

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/13$ gcc 13.c

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/13$ ./a.out
You have 10 seconds to type something:
hello
You typed: hello

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/13$ ./a.out
You have 10 seconds to type something:
No input after 10 seconds.

*/
