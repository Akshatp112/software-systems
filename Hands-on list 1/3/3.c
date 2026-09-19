/*
3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    // create file with rw-r--r-- permissions
    fd = creat("myfile.txt", 0644);

    if (fd < 0) {
        perror("creat");
        return 1;
    }

    printf("File created successfully. File Descriptor: %d\n", fd);

    close(fd);

    return 0;
}

/*
aksht@HP-Pavilion:~/software-systems/Hands-on list 1/3$ gcc 3.c -o 3
aksht@HP-Pavilion:~/software-systems/Hands-on list 1/3$ ./3
File created successfully. File Descriptor: 3

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/3$ ls -l
total 20
-rwxr-xr-x 1 aksht aksht 16080 Sep 18 06:52 3
-rw-r--r-- 1 aksht aksht   443 Sep 18 06:51 3.c
-rw-r--r-- 1 aksht aksht     0 Sep 18 06:52 myfile.txt
*/
