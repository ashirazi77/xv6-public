#include "types.h"
#include "user.h"
#include "stat.h"

int main(int argc, char *argv[])
{
    int i, j;
    setpriority(30);

    for(i=0;i<43000;i++){
        asm("nop");
        for(j = 0; j < 43000; j++) {
            asm("nop");
        }
    }
    exit(0);
    return 0;
}
