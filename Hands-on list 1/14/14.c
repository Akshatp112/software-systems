/*
14 Write a program to find the type of a file.
 a. Input should be taken from command line.
 b. program should be able to identify any type of a file. 
*/

#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    struct stat st;

    if (argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    if (lstat(argv[1], &st) == -1)
    {
        perror("lstat");
        return 1;
    }


    if (S_ISREG(st.st_mode))
        printf("Regular File\n");
    else if (S_ISDIR(st.st_mode))
        printf("Directory\n");
    else if (S_ISLNK(st.st_mode))
        printf("Symbolic Link\n");
    else if (S_ISCHR(st.st_mode))
        printf("Character Device\n");
    else if (S_ISBLK(st.st_mode))
        printf("Block Device\n");
    else if (S_ISFIFO(st.st_mode))
        printf("FIFO (Pipe)\n");
    else if (S_ISSOCK(st.st_mode))
        printf("Socket\n");
    else
        printf("Unknown\n");

    return 0;
}

/*

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/14$ gcc 14.c

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/14$ ./a.out file.txt
lstat: No such file or directory

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/14$ ./a.out .
Directory

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/14$ touch file.txt

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/14$ ./a.out file.txt
Regular File

*/
