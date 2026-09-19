/*
1. Create the following types of a files using (i) shell command (ii) system call
 a. soft link (symlink system call)
 b. hard link (link system call)
 c. FIFO (mkfifo Library Function or mknod system call)
*/

#include <unistd.h>
#include <sys/stat.h>

int main() {
    symlink("f1.txt", "softlink_f1");   //soft link
    link("f1.txt", "hardlink_f1");      //hard link
    mkfifo("myfifo", 0666);             //FIFO
    return 0;
}


/*
aksht@HP-Pavilion:~/software-systems/Hands-on list 1/01$ echo "hello, this is content of f1" > f1.txt
aksht@HP-Pavilion:~/software-systems/Hands-on list 1/01$ gcc 1.c -o 1
aksht@HP-Pavilion:~/software-systems/Hands-on list 1/01$ ./1
aksht@HP-Pavilion:~/software-systems/Hands-on list 1/01$ ls -l
total 28
-rwxr-xr-x 1 aksht aksht 16016 Sep 19 16:19 1
-rw-r--r-- 1 aksht aksht   223 Sep 18 06:06 1.c
-rw-r--r-- 2 aksht aksht    29 Sep 19 16:17 f1.txt
-rw-r--r-- 2 aksht aksht    29 Sep 19 16:17 hardlink_f1
prw-r--r-- 1 aksht aksht     0 Sep 18 06:08 myfifo
lrwxrwxrwx 1 aksht aksht     6 Sep 18 06:08 softlink_f1 -> f1.txt
aksht@HP-Pavilion:~/software-systems/Hands-on list 1/01$ cat hardlink_f1
hello, this is content of f1
aksht@HP-Pavilion:~/software-systems/Hands-on list 1/01$ cat softlink_f1
hello, this is content of f1
aksht@HP-Pavilion:~/software-systems/Hands-on list 1/01$ cat myfifo
hello from terminal 2
*/
