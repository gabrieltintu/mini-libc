#include <time.h>
#include <stddef.h>
#include <internal/syscall.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    int ret = syscall(35, req, rem);

    if (ret >= 0)
        return ret;

    return -1;
}
