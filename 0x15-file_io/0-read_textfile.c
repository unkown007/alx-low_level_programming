#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - reads a text file and printss it tp the POSIX
 * standard output
 * @filename: path to the file
 * @letters: number of letters
 *
 * Return: numbers of letters it could read and print,
 * if the file cannot be opened or read then 0,
 * if the filename is NULL then 0
 * if write fails or does not write the expected amount of bytes then 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n;
	char *buff;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buff = malloc(letters * sizeof(char));
	if (buff == NULL)
		return (0);
	n = read(fd, buff, letters);
	if (write(1, buff, n) != n)
		return (0);
	close(fd);
	free(buff);
	return (n);
}
