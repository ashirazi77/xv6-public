#include "user.h"
#include "types.h"

int main(int argc, char *argv[])
{
    printf(1, "This program is a Test for waitpid() \n");
    int status, pid, i;
    for (i = 0; i < 5; i++)
    {
        pid = fork();
        if (!pid)
        { //child
            sleep(8);
            printf(1, "Child PID = %d exited with: status = %d\n", getpid(), getpid() + 3);
            exit(getpid() + 3);
        }
        else
        {
            //parent
            sleep(5);
            printf(1, "Parent waiting for Child PID = %d \n", pid);
            waitpid(pid, &status, 0);
            printf(1, "Child PID = %d exited with: status = %d\n\n", pid, status);
        }
    }
    exit(0);
    return 0;
}