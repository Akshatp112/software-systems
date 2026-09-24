/*
18. Record Locking

a. Implement write lock
b. Implement read lock

Create three records in a file. Whenever you access a
particular record, first lock it and then modify/access it.
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define RECORDS 3

int main() {
    int fd;
    int choice, rec_no, data;

    // Open/create the file
    fd = open("records.txt", O_CREAT | O_RDWR, 0644);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    /*
     Create 3 records if the file is empty.
     Records: 0,0,0
     */
    if (lseek(fd, 0, SEEK_END) == 0) {
        int records[RECORDS] = {0, 0, 0};

        write(fd, records, sizeof(records));

        printf("Three records created: 0 0 0\n");
    }

    printf("\n1. Read a record\n");
    printf("2. Write a record\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter record number (0-2): ");
    scanf("%d", &rec_no);

    if (rec_no < 0 || rec_no >= RECORDS) {
        printf("Invalid record number.\n");
        close(fd);
        return 1;
    }

    // Create lock structure
    struct flock fl = {0};

    fl.l_whence = SEEK_SET;

    // Each record is an integer
    fl.l_start = rec_no * sizeof(int);
    fl.l_len = sizeof(int);

    /*
    READ LOCK
    */
    if (choice == 1) {

        fl.l_type = F_RDLCK;

        // Wait until read lock can be acquired
        if (fcntl(fd, F_SETLKW, &fl) == -1) {
            perror("fcntl");
            close(fd);
            return 1;
        }

        printf("\nRecord %d locked for reading.\n", rec_no);

        // Move to the required record
        lseek(fd, rec_no * sizeof(int), SEEK_SET);

        // Read the record
        if (read(fd, &data, sizeof(int)) == -1) {
            perror("read");
        } else {
            printf("Record %d = %d\n", rec_no, data);
        }
    }

    /*
     WRITE LOCK
    */
    else if (choice == 2) {

        fl.l_type = F_WRLCK;

        // Wait until write lock can be acquired
        if (fcntl(fd, F_SETLKW, &fl) == -1) {
            perror("fcntl");
            close(fd);
            return 1;
        }

        printf("\nRecord %d locked for writing.\n", rec_no);

        printf("Enter new value: ");
        scanf("%d", &data);

        // Move to the required record
        lseek(fd, rec_no * sizeof(int), SEEK_SET);

        // Write the new value
        if (write(fd, &data, sizeof(int)) == -1) {
            perror("write");
        } else {
            printf("Record %d updated to %d\n", rec_no, data);
        }
    }

    else {
        printf("Invalid choice.\n");
        close(fd);
        return 1;
    }

    /*
     UNLOCK
    */
    fl.l_type = F_UNLCK;

    if (fcntl(fd, F_SETLK, &fl) == -1) {
        perror("unlock");
    } else {
        printf("Record %d unlocked.\n", rec_no);
    }

    close(fd);

    return 0;
}
/*

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/18$ ./a.out

1. Read a record
2. Write a record
Enter your choice: 1
Enter record number (0-2): 1

Record 1 locked for reading.
Record 1 = 100
Record 1 unlocked.

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/18$ ./a.out

1. Read a record
2. Write a record
Enter your choice: 2
Enter record number (0-2): 1

Record 1 locked for writing.
Enter new value: 20
Record 1 updated to 20
Record 1 unlocked.

*/
