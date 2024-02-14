#ifndef __TIME_H__
#define __TIME_H__ 1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/types.h>

struct timespec {
	int sec;
	long nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);
unsigned int sleep(unsigned int sec);

#ifdef __cplusplus
}
#endif

#endif
