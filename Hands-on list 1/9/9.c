/*
9. Write a program to print the following information about a given file.
 a. inode
 b. number of hard links
 c. uid
 d. gid
 e. size
 f. block size
 g. number of blocks
 h. time of last access
 i. time of last modification
 j. time of last change
*/

#include <stdio.h> //for stat()
#include <sys/stat.h> //for close()
#include <unistd.h> //for printf(), perror()
#include <time.h> // for ctime()

int main()
{
    struct stat st;

    if (stat("file.txt", &st) == -1)
    {
        perror("stat");
        return 1;
    }

    printf("Inode number       : %ld\n", st.st_ino);
    printf("Hard links         : %ld\n", st.st_nlink);
    printf("User ID            : %d\n", st.st_uid);
    printf("Group ID           : %d\n", st.st_gid);
    printf("File size          : %ld bytes\n", st.st_size);
    printf("Block size         : %ld bytes\n", st.st_blksize);
    printf("Blocks             : %ld\n", st.st_blocks);
    printf("Last access time   : %s", ctime(&st.st_atime));
    printf("Last modification  : %s", ctime(&st.st_mtime));
    printf("Last status change : %s", ctime(&st.st_ctime));

    return 0;
}

/*

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/9$ nano file.txt

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/9$ gcc 9.c

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/9$ ./a.out
Inode number       : 48624
Hard links         : 1
User ID            : 1000
Group ID           : 1000
File size          : 29 bytes
Block size         : 4096 bytes
Blocks             : 8
Last access time   : Fri Sep 18 13:27:22 2026
Last modification  : Fri Sep 18 13:27:34 2026
Last status change : Fri Sep 18 13:27:34 2026

*/
