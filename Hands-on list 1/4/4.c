/*
4. Write a program to open an existing file with read write mode. Try O_EXCL flag also. 
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    // Try to open existing file "myfile.txt" in read-write mode
    fd = open("myfile.txt", O_RDWR);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    printf("File opened successfully in read-write mode. FD: %d\n", fd);
    close(fd);

    // Now try opening with O_EXCL along with O_CREAT
    fd = open("myfile2.txt", O_RDWR | O_CREAT | O_EXCL, 0644);

    if (fd < 0) {
        perror("open with O_EXCL");
    } else {
        printf("File opened with O_EXCL. FD: %d\n", fd);
        close(fd);
    }

    return 0;
}


/*
aksht@HP-Pavilion:~/software-systems/Hands-on list 1/4$ gcc 4.c -o 4
aksht@HP-Pavilion:~/software-systems/Hands-on list 1/4$ touch myfile.txt

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/4$ ./4
File opened successfully in read-write mode. FD: 3
open with O_EXCL: File exists

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/4$ ls -l
total 20
-rwxr-xr-x 1 aksht aksht 16080 Sep 18 12:16 4
-rw-r--r-- 1 aksht aksht   627 Sep 18 12:15 4.c
-rw-r--r-- 1 aksht aksht     0 Sep 18 12:15 myfile.txt
*/
