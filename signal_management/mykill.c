#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
    if (argc != 4) {
        printf("Usage: %s <pid> <signal-number> <value>\n", argv[0]);
        return 1;
    }
        printf("pid=%d\n",getpid());
    int pid = atoi(argv[1]);
    int sig = atoi(argv[2]);
    int value = atoi(argv[3]);

    union sigval sv;
    sv.sival_int = value;

    if (sigqueue(pid, sig, sv) == -1) {
        perror("sigqueue failed");
        return 1;
    }

    printf("Sent signal %d with value %d to PID %d\n", sig, value, pid);
    return 0;
}

