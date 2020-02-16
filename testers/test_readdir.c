#include <dirent.h>
#include <stdio.h>

int main(void)
{
	char root[2] = "/";
	DIR	*dirp;
	struct dirent *dir;
	int a = 0;

	dirp = opendir(root);
	while ((dir = readdir(dirp)))
	{
		a++;
	}
	return (0);
}
