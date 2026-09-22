/*
21. Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file. 
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd = open("shared.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        write(fd, "Child writing...\n", strlen("Child writing...\n"));
    } else {
        // Parent process
        write(fd, "Parent writing...\n", strlen("Parent writing...\n"));
    }

    close(fd);
    return 0;
}

/*

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/21$ gcc 21.c

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/21$ ./a.out

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/21$ cat shared.txt
Parent writing...
Child writing...

Note : Order may very due to scheduling

*/
