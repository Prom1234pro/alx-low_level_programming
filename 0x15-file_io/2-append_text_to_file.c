#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * append_text_to_file - appends text to a file
 * @filename: the name of the file
 * @text_content: the text to append
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int my_file, write_bytes = 0;

	if (filename == NULL)
		return (-1);

	my_file = open(filename, O_WRONLY | O_APPEND);
	if (my_file == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[write_bytes])
			write_bytes++;

		write_bytes = write(my_file, text_content, write_bytes);
		if (write_bytes == -1)
		{
			close(my_file);
			return (-1);
		}
	}

	close(my_file);
	return (1);
}
