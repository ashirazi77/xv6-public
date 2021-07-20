#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
    printf(1, "Testing Part C waitpid() \n");
    int status, pid, i;
    for(i = 0; i < 5; i++) {
        pid = fork();
        if (!pid) { //child
            sleep(15);
            printf(1, "Child with PID: %d exiting with status %d\n", getpid(), getpid() + 1);
            exit(getpid() + 1);
        } else { //parent
            sleep(10);
            printf(1, "Parent waiting for child with PID: %d \n", pid);
            waitpid(pid, &status, 0);
            printf(1, "Child %d has exited with status %d\n\n", pid, status);
        }
    }
    exit(0);
    return 0;
}