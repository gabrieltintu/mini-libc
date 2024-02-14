#include <time.h>
#include <stddef.h>

unsigned int sleep(unsigned int sec)
{
    struct timespec wait = {sec, 0};
    nanosleep(&wait, NULL);
    return 0;
}
