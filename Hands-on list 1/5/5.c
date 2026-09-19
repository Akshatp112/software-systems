/*
5. Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd[5];

    fd[0] = creat("file1.txt", 0644);
    fd[1] = creat("file2.txt", 0644);
    fd[2] = creat("file3.txt", 0644);
    fd[3] = creat("file4.txt", 0644);
    fd[4] = creat("file5.txt", 0644);

    for (int i = 0; i < 5; i++)
    {
        if (fd[i] == -1)
        {
            perror("creat");
            return 1;
        }
    }

    printf("Five files created\n");
    printf("PID = %d\n", getpid());

    while (1)
    {
        sleep(15);
    }

    return 0;
}

/*
aksht@HP-Pavilion:~/software-systems/Hands-on list 1/5$ gcc 5.c

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/5$ ./a.out &
[2] 2301
Five files created
PID = 2301

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/5$ ls -l
total 20
-rw-r--r-- 1 aksht aksht   725 Sep 18 12:28 5.c
-rwxr-xr-x 1 aksht aksht 16216 Sep 18 12:29 a.out
-rw-r--r-- 1 aksht aksht     0 Sep 18 12:30 file1.txt
-rw-r--r-- 1 aksht aksht     0 Sep 18 12:30 file2.txt
-rw-r--r-- 1 aksht aksht     0 Sep 18 12:30 file3.txt
-rw-r--r-- 1 aksht aksht     0 Sep 18 12:30 file4.txt
-rw-r--r-- 1 aksht aksht     0 Sep 18 12:30 file5.txt

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/5$ ls -l /proc/2301/fd
total 0
lrwx------ 1 aksht aksht 64 Sep 18 12:30 0 -> /dev/pts/0
lrwx------ 1 aksht aksht 64 Sep 18 12:30 1 -> /dev/pts/0
lrwx------ 1 aksht aksht 64 Sep 18 12:30 2 -> /dev/pts/0
l-wx------ 1 aksht aksht 64 Sep 18 12:30 3 -> '/home/aksht/software-systems/Hands-on list 1/5/file1.txt'
l-wx------ 1 aksht aksht 64 Sep 18 12:30 4 -> '/home/aksht/software-systems/Hands-on list 1/5/file2.txt'
l-wx------ 1 aksht aksht 64 Sep 18 12:30 5 -> '/home/aksht/software-systems/Hands-on list 1/5/file3.txt'
l-wx------ 1 aksht aksht 64 Sep 18 12:30 6 -> '/home/aksht/software-systems/Hands-on list 1/5/file4.txt'
l-wx------ 1 aksht aksht 64 Sep 18 12:30 7 -> '/home/aksht/software-systems/Hands-on list 1/5/file5.txt'

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/5$ kill 2301
[2]-  Terminated                 ./a.out
*/

