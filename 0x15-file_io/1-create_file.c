#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

#define PERMS 0600

/**
 * create_file - create a file
 * @filename: name of the file created
 * @text_content: NULL terminated string to wirte to the file
 *
 * Return: 1 on success, or -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	size_t size;

	if (filename == NULL)
		return (-1);
	fd = creat(filename, PERMS);
	if (fd == -1)
		return (-1);
	if (text_content != NULL)
	{
		for (size = 0; text_content[size]; size++)
			;
		if (write(fd, text_content, size) == -1)
			return (-1);
	}
	return (1);
}
