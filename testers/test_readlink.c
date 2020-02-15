#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char buf[20];
	readlink("12345678", buf, 20);
	perror("");
	printf("%s\n", buf);
	return (0);
}
