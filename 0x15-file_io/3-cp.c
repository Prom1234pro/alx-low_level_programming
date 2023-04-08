#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 1024

/**
 * print_usage_and_exit - print usage and exit
 * @progname: pointer to program name of file to create
 *
 * Return: void
 */

void print_usage_and_exit(const char *progname)
{
	dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", progname);
	exit(97);
}

/**
 * print_read_error_and_exit - print read error and exit
 * @filename: pointer to name of file to create
 *
 * Return: void
 */

void print_read_error_and_exit(const char *filename)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	exit(98);
}

/**
 * print_write_error_and_exit - reads
 * @filename: pointer to name of file to create
 *
 * Return: void
 */

void print_write_error_and_exit(const char *filename)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
	exit(99);
}

/**
 * print_close_error_and_exit - reads
 * @fd: pointer to name of file to create
 *
 * Return: void
 */

void print_close_error_and_exit(int fd)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
}

/**
 * main - reads a text file and prints it to the POSIX stdout
 * @argc: pointer to name of file to create
 * @argv: pointer to content to write
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	const char *file_from = argv[1];
	const char *file_to = argv[2];
	ssize_t read_bytes, write_bytes;
	char buf[BUFSIZE];
	int fd_from = open(file_from, O_RDONLY);
	int fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (argc != 3)
		print_usage_and_exit(argv[0]);

	if (fd_from == -1)
		print_read_error_and_exit(file_from);

	if (fd_to == -1)
		print_write_error_and_exit(file_to);

	while ((read_bytes = read(fd_from, buf, BUFSIZE)) > 0)
	{
		write_bytes = write(fd_to, buf, read_bytes);
		if (write_bytes == -1 || write_bytes != read_bytes)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			close(fd_from);
			close(fd_to);
			exit(99);
		}
	}

	if (read_bytes == -1)
		print_read_error_and_exit(file_from);

	if (close(fd_from) == -1)
		print_close_error_and_exit(fd_from);

	if (close(fd_to) == -1)
		print_close_error_and_exit(fd_to);

	return (0);
}
