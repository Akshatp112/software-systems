/*
16. Write a program to perform mandatory locking.
 a. Implement write lock
 b. Implement read lock
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

static int lock_region(int fd, short type) {
    struct flock fl = {0};
    fl.l_type = type;     // F_WRLCK, F_RDLCK, or F_UNLCK
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;         // lock whole file
    return fcntl(fd, F_SETLKW, &fl);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file> <r|w|u>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_CREAT | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    char mode = argv[2][0];

    if (mode == 'w') {
        if (lock_region(fd, F_WRLCK) < 0) perror("F_WRLCK");
        else printf("Write lock acquired on %s\n", argv[1]);
    } else if (mode == 'r') {
        if (lock_region(fd, F_RDLCK) < 0) perror("F_RDLCK");
        else printf("Read lock acquired on %s\n", argv[1]);
    } else if (mode == 'u') {
        if (lock_region(fd, F_UNLCK) < 0) perror("F_UNLCK");
        else printf("Lock released on %s\n", argv[1]);
    } else {
        fprintf(stderr, "mode must be r/w/u\n");
    }

    pause(); // keep lock until terminated
    close(fd);
    return 0;
}

/*

Terminal 1:

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/16$ gcc 16.c -o lock

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/16$ ./lock test.txt w
Write lock acquired on test.txt

   -> program waits here (pause)


Terminal 2:

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/16$ ./lock test.txt r

   -> This will block until Terminal 1 releases the lock (Ctrl+C)


Terminal 1: release lock

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/16$ ./lock test.txt w
Write lock acquired on test.txt
^C


Terminal 2: read lock acquired

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/16$ ./lock test.txt r
Read lock acquired on test.txt
*/
