/*
11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
 a. use dup
 b. use dup2
 c. use fcn
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main() {
    int fd, fd_dup;

    fd = open("append.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    fd_dup = fcntl(fd, F_DUPFD, 10);
    if (fd_dup < 0) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    write(fd, "Line 1 using fd\n", strlen("Line 1 using fd\n"));
    write(fd_dup, "Line 2 using fd_dup\n", strlen("Line 2 using fd_dup\n"));

    close(fd);
    close(fd_dup);

    return 0;
}

/*

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/11$ > append.txt

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/11$ gcc 11c.c -o 11c

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/11$ ./11c

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/11$ cat append.txt
Line 1 using fd
Line 2 using fd_dup

*/
