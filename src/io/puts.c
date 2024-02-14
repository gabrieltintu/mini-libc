#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int puts(const char *str)
{
	/* Implement puts(). */
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}

	write(1, str, i);
	write(1, "\n", 1);
	return 0;
}
