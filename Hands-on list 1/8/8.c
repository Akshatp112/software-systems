/*
8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
*/

#include <unistd.h>   // for read(), write(), close()
#include <fcntl.h>    // for open()
#include <stdio.h>    // for perror()

#define BUF_SIZE 1    // read one character at a time

int main() {
    int fd;
    char c;

    // Open file in read-only mode
    fd = open("file.txt", O_RDONLY);
    if (fd < 0) {
        perror("open file1.txt");
        return 1;
    }

    // Read file character by character
    while (read(fd, &c, BUF_SIZE) > 0) {
        write(1, &c, 1);  // print character to stdout
    }

    close(fd);
    return 0;
}

/*
aksht@HP-Pavilion:~/software-systems/Hands-on list 1/8$ printf "first line\nsecond line\nthird line\n" > file.txt

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/8$ gcc 8.c

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/8$ ./a.out
first line
second line
third line

*/
