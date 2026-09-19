/*
6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls 
*/

#include <unistd.h>  // for read() and write()

int main() {
    char c;

    // Keep reading characters until EOF (Ctrl+D)
    while (read(0, &c, 1) > 0) {
        write(1, &c, 1);  // write each character immediately
    }

    return 0;
}

/*

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/6$ gcc 6.c

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/6$ ./a.out
hello
hello
hello 2
hello 2

*/
