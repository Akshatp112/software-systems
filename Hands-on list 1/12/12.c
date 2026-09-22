/*
12. Write a program to find out the opening mode of a file. Use fcntl
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("mode.txt", O_RDWR | O_CREAT, 0644);

    if(fd < 0)
    {
	perror("open");
	return -1;
    }

    int flags = fcntl(fd, F_GETFL);

    if ((flags & O_ACCMODE) == O_RDONLY) 
        printf("File opened in read-only mode\n");
    else if ((flags & O_ACCMODE) == O_WRONLY) 
        printf("Write Only\n");
    else 
        printf("Read & Write\n");

    close(fd);
    return 0;
}

/*

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/12$ gcc 12.c

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/12$ ./a.out
Read & Write

*/

