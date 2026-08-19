#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void close_file(int fd);
int open_file_from(const char *filename);
int open_file_to(const char *filename);
void copy_content(int fd_from, int fd_to, char *file_from, char *file_to);

/**
 * close_file - closes a file descriptor, exiting with code 100 on failure
 * @fd: the file descriptor to close
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * open_file_from - opens a file for reading, exiting with code 98 on
 * failure
 * @filename: the name of the file to open
 *
 * Return: the file descriptor
 */
int open_file_from(const char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", filename);
		exit(98);
	}
	return (fd);
}

/**
 * open_file_to - opens a file for writing, exiting with code 99 on
 * failure
 * @filename: the name of the file to open
 *
 * Return: the file descriptor
 */
int open_file_to(const char *filename)
{
	int fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
	return (fd);
}

/**
 * copy_content - copies the content of one file descriptor to another,
 * 1024 bytes at a time
 * @fd_from: the file descriptor to read from
 * @fd_to: the file descriptor to write to
 * @file_from: the name of the source file, used in error messages
 * @file_to: the name of the destination file, used in error messages
 */
void copy_content(int fd_from, int fd_to, char *file_from, char *file_to)
{
	char buffer[BUFFER_SIZE];
	ssize_t r, w;

	r = read(fd_from, buffer, BUFFER_SIZE);
	while (r > 0)
	{
		w = write(fd_to, buffer, r);
		if (w == -1 || w != r)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file_to);
			exit(99);
		}
		r = read(fd_from, buffer, BUFFER_SIZE);
	}
	if (r == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", file_from);
		exit(98);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: the number of arguments
 * @argv: the arguments vector
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open_file_from(argv[1]);
	fd_to = open_file_to(argv[2]);

	copy_content(fd_from, fd_to, argv[1], argv[2]);

	close_file(fd_from);
	close_file(fd_to);

	return (0);
}
