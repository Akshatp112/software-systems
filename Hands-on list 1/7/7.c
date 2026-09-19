/*
7. Write a program to copy file1 into file2 ($cp file1 file2).
*/

#include <unistd.h>   // for read(), write(), close()
#include <fcntl.h>    // for open()
#include <stdio.h>    // for perror()

#define BUF_SIZE 1024

int main() {
    int fd1, fd2;
    char buffer[BUF_SIZE];
    ssize_t n;

    // Open source file (file1) for reading
    fd1 = open("f1.txt", O_RDONLY);
    if (fd1 < 0) {
        perror("open file1");
        return 1;
    }

    // Open destination file (file2) for writing (create if not exists)
    fd2 = open("f2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 < 0) {
        perror("open file3");
        close(fd1);
        return 1;
    }

    // Copy contents from file1 to file2
    while ((n = read(fd1, buffer, BUF_SIZE)) > 0) {
        if (write(fd2, buffer, n) != n) {
            perror("write");
            close(fd1);
            close(fd2);
            return 1;
        }
    }

    if (n < 0) {
        perror("read");
    }

    // Close files
    close(fd1);
    close(fd2);

    return 0;
}

/*

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/7$ gcc 7.c

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/7$ echo "This is content of file 1" > f1.txt

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/7$ ./a.out

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/7$ ls -l
total 28
-rw-r--r-- 1 aksht aksht  1045 Sep 18 12:52 7.c
-rwxr-xr-x 1 aksht aksht 16168 Sep 18 12:53 a.out
-rw-r--r-- 1 aksht aksht    26 Sep 18 12:53 f1.txt
-rw-r--r-- 1 aksht aksht    26 Sep 18 12:53 f2.txt

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/7$ cat f2.txt
This is content of file 1

*/
