/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice_inspect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 00:20:56 by tango             #+#    #+#             */
/*   Updated: 2020/01/18 23:18:21 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>

int		main(int ac, char **av)
{
	struct stat sb;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s <pathname> \n", av[0]);
		return (1);
	}
	printf("av[1] is : %s\n", av[1]);
	errno = 5;
	printf("errno is %d\n", errno);
	if (stat(av[1], &sb) == -1)
	{
		printf("errno is %d\n", errno);
		perror("fuck");
		return (1);
	}
	printf("File type :          ");
	switch (sb.st_mode & S_IFMT)
	{
		case S_IFBLK:	printf("block dvice\n");		break;
		case S_IFCHR:	printf("character device\n");	break;
		case S_IFDIR:	printf("directory\n");			break;
		case S_IFIFO:	printf("FIFO/pipe\n");			break;
		case S_IFLNK:	printf("symlink\n");			break;
		case S_IFREG:	printf("regular file\n");		break;
		case S_IFSOCK:	printf("socket\n");				break;
		default:		printf("unknown?\n");			break;
	}
	printf("I-node number: %ld\n", (long) sb.st_ino);
	printf("Mode: %lo (octal)\n", (unsigned long) sb.st_mode);
	printf("Link count: %ld\n", (long) sb.st_nlink);
	printf("Ownership: UID=%ld GID=%ld\n", (long) sb.st_uid, (long) sb.st_gid);
	printf("Preferred I/O block size: %ld bytes\n", (long) sb.st_blksize);
	printf("File size: %lld bytes\n", (long long) sb.st_size);
	printf("Blocks allocated: %lld\n", (long long) sb.st_blocks);
	printf("Last status change: %s", ctime(&sb.st_ctime));
	printf("Last file access: %s", ctime(&sb.st_atime));
	printf("Last file modification: %s", ctime(&sb.st_mtime)); 

/*
**	permission bits
*/
	printf("S_IRWXU is %d\n", sb.st_mode & S_IRWXU);
	printf("S_IRWXG is %d\n", sb.st_mode & S_IRWXG);
	printf("S_IRWXO is %d\n", sb.st_mode & S_IRWXO);
/*
**	bitwise operation practice
*/
	unsigned short mask = 0777;
	printf("%o(octal)\n", (sb.st_mode & mask));
/*
**
*/
	if (sb.st_ctime)
	{
		printf("sb.st_mtime exist\n");
		printf("the value is %ld\n", sb.st_mtime);
	}
	printf("%s\n", ctime(&sb.st_mtime));
	return (0);
}
