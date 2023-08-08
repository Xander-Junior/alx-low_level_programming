#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * error_exit - Prints an error message and exits with the given code.
 * @code: Exit code.
 * @msg: Error message.
 */
void error_exit(int code, const char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(code);
}

/**
 * main - Entry point of the program.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 *
 * Return: 0 on success, 97, 98, 99, or 100 on failure.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t read_bytes, write_bytes;
	char buffer[1024];

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file");

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		error_exit(99, "Error: Can't write to file");

	while ((read_bytes = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		write_bytes = write(fd_to, buffer, read_bytes);
		if (write_bytes == -1 || write_bytes != read_bytes)
			error_exit(99, "Error: Can't write to file");
	}

	if (read_bytes == -1)
		error_exit(98, "Error: Can't read from file");

	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close fd");
	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd");

	return (EXIT_SUCCESS);
}


