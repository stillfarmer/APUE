#include <stdio.h>
#include <errno.h>
#include <string.h> /* add to avoid warning, %s, type of int, but why ?*/

void main(void)
{
    printf("errno = %d\n", errno);
	printf("error msg = %s\n", strerror(errno));
	printf("error msg = %s\n", strerror(1));
	perror(strerror(2));
}
