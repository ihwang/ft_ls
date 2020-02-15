#include <dirent.h>

int main(void)
{
	DIR *dirp;

	dirp = opendir("testdir");
	closedir(dirp);

	return (0);
}
