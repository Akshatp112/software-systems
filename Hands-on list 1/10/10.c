/*
10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
 a. check the return value of lseek
 b. open the file with od and check the empty spaces in between the data. 
*/

#include <unistd.h>   // for write(), dup(), close()
#include <fcntl.h>    // for open()
#include <stdio.h>    // for perror()

int main() {
    int fd;
    
    // Open file for writing (create if it doesn't exist)
    fd = open("lseek.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Write 10 bytes initial data
    write(fd, "HelloWorld", 10);

    // Move file pointer 10 bytes ahead (creates a hole)
    lseek(fd, 10, SEEK_CUR);

    // Write more 10 bytes data after the hole
    write(fd, "afterlseek", 10);

    close(fd);
    return 0;
}

/*

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/10$ gcc 10.c

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/10$ ./a.out

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/10$ ls -l
total 24
-rw-r--r-- 1 aksht aksht   873 Sep 20 16:56 10.c
-rwxr-xr-x 1 aksht aksht 16120 Sep 20 16:56 a.out
-rw-r--r-- 1 aksht aksht    30 Sep 20 16:57 lseek.txt

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/10$ od -c lseek.txt
0000000   H   e   l   l   o   W   o   r   l   d  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   a   f   t   e   r   l   s   e   e   k
0000036

*/
