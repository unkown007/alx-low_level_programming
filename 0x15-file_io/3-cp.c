#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define PERMS 0664
#define BUFF_SIZE 1024

/**
 * _copy - copy a file's content to another file
 * @fd_1: first file descriptor
 * @fd_2: second file descriptor
 * @f1: first file's name
 * @f2: second file's name
 */
void _copy(int fd_1, int fd_2, char *f1, char *f2)
{
	ssize_t r, w;
	char buff[BUFF_SIZE];

	do {
		r = read(fd_1, buff, BUFF_SIZE);
		if (r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", f1);
			exit(98);
		}
		w = write(fd_2, buff, (size_t) r);
		if (w == -1 || w != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", f2);
			exit(99);
		}
		memset(buff, '0', BUFF_SIZE);
	} while (r != 0);
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_1, fd_2;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_1 = open(argv[1], O_RDONLY);
	if (fd_1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fd_2 = creat(argv[2], PERMS);
	if (fd_2 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	_copy(fd_1, fd_2, argv[1], argv[2]);

	if (close(fd_1) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_1);
		exit(100);
	}
	if (close(fd_2) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_2);
		exit(100);
	}
	return (0);
}
