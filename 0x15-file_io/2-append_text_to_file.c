#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * append_text_to_file - appends text at end of a file
 * @filename: name of the file
 * @text_content: NULL terminated string
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	ssize_t size;
	int fd;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_RDWR | O_APPEND);
	if (fd == -1)
		return (-1);
	if (text_content != NULL)
	{
		for (size = 0; text_content[size]; size++)
			;
		if (write(fd, text_content, size) != size)
			return (-1);
	}
	return (1);
}
