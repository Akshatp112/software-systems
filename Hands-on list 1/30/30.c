/*
30. Write a program to run a script at a specific time using a Daemon process.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <HH> <MM>\n", argv[0]);
        exit(1);
    }

    int target_hour = atoi(argv[1]);
    int target_min = atoi(argv[2]);

    // Fork and exit parent
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    if (pid > 0) {
        printf("Daemon started with PID %d\n", pid); //child pid
        exit(0);
    }

    // Create new session and daemonize
    setsid();
    chdir("/");
    umask(0);

    while (1) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        if (t->tm_hour == target_hour && t->tm_min == target_min) {
            system("bash '/home/aksht/software-systems/Hands-on list 1/30/myscript.sh'");  // <-- Replace with your script path
            sleep(60);  // wait 1 min so it doesn’t run multiple times
        }

        sleep(10);  // check every 10s
    }

    return 0;
}

/*

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/30$ gcc 30.c

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/30$ nano myscript.sh

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/30$ ./myscript.sh

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/30$ ./a.out 19 08
Daemon started with PID 3327

aksht@HP-Pavilion:~/software-systems/Hands-on list 1/30$ cat /tmp/output.txt
Script executed at Fri Sep 25 18:55:31 UTC 2026
Script executed at Fri Sep 25 18:56:27 UTC 2026
Script executed at Fri Sep 25 19:05:28 UTC 2026
Script executed at Fri Sep 25 19:06:47 UTC 2026
Script executed at Fri Sep 25 19:08:05 UTC 2026

*/
