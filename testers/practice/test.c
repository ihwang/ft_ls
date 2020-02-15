#include <string.h>
#include <stdio.h>

char *foo()
{
	char buf[10];

	buf = strcpy(buf, "123abcd");
	return (buf);
}

int main(void)
{
	printf("%s\n", foo());
	return (0);
}
