#include "types.h"
#include "user.h"

int main(int argc, char **argv)
{
    int i, j;
    setpriority(30);

    for(i=0;i<50000;i++){
        asm("nop");
        for(j = 0; j < 50000; j++) {
            asm("nop");
        }
    }
    exit(0);
}
