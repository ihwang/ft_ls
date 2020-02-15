#include <stdio.h>
#include <sys/stat.h>

int	main(int ac, char **av)
{
	struct stat sb;
	ac = 0;
	lstat(av[1], &sb);
	printf("%d\n", sb.st_mode);
	return (0);
}
