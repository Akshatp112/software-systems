/*
17. Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int tickets = 0;

    fd = open("tickets.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    if (write(fd, &tickets, sizeof(int)) != sizeof(int))
    {
        perror("write");
        close(fd);
        return 1;
    }

    printf("Ticket file initialized to 0\n");

    close(fd);

    return 0;
}


