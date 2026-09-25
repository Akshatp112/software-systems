/*
Write a separate program, to
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
    struct flock fl = {0};

    fd = open("tickets.txt", O_RDWR);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;

    if (fcntl(fd, F_SETLKW, &fl) == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Lock acquired. Reserving ticket...\n");

    if (read(fd, &tickets, sizeof(int)) != sizeof(int))
    {
        perror("read");
        close(fd);
        return 1;
    }

    tickets++;

    lseek(fd, 0, SEEK_SET); //moving offset to start

    if (write(fd, &tickets, sizeof(int)) != sizeof(int))
    {
        perror("write");
        close(fd);
        return 1;
    }

    printf("Ticket reserved. Total tickets: %d\n", tickets);

    fl.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &fl);

    close(fd);

    return 0;
}

/*

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/17$ gcc 17.c

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/17$ gcc 17b.c -o 17b

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/17$ ./a.out
Ticket file initialized to 0

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/17$ ./17b
Lock acquired. Reserving ticket...
Ticket reserved. Total tickets: 1

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/17$ ./17b
Lock acquired. Reserving ticket...
Ticket reserved. Total tickets: 2

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/17$ ./17b
Lock acquired. Reserving ticket...
Ticket reserved. Total tickets: 3

*/
