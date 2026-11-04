#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void handler(int sig, siginfo_t *info, void *context)
{
    printf("\n=== SIGNAL RECEIVED ===\n");
    printf("Signal number   : %d\n", sig);
    printf("Signal code     : %d (SI_USER=%d, SI_QUEUE=%d, SI_KERNEL=%d)\n",
           info->si_code, SI_USER, SI_QUEUE, SI_KERNEL);

    printf("Sender PID      : %d\n", info->si_pid);
    printf("Sender UID      : %d\n", info->si_uid);
    printf("User data (int) : %d\n", info->si_value.sival_int);

    printf("========================\n\n");
}

int main()
{
    struct sigaction sa;

    printf("Process PID = %d\n", getpid());

    memset(&sa, 0, sizeof(sa));
    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;   // <-- enables siginfo_t

    // Register handlers
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    // Wait forever
   while (1) {
       printf("Waiting for SIGUSR1 / SIGUSR2...\n");
        sleep(4);
    }

    return 0;
}

