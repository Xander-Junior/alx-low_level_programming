#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include "main.h"



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
 * print_magic - Prints the ELF magic number.
 * @magic: Pointer to the magic number bytes.
 */
void print_magic(unsigned char *magic)
{
	int i = 0;
	printf("  Magic:   ");
	for (i = 0; i < 16; i++)
	{
		printf("%02x", magic[i]);
		if (i < 15)
			printf(" ");
	}
	printf("\n");
}

/**
 * main - Entry point of the program.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 *
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
		error_exit(98, "Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit(98, "Error: Cannot read file");

	if (read(fd, &header, sizeof(header)) != sizeof(header))
		error_exit(98, "Error: Cannot read ELF header");

	printf("ELF Header:\n");
	print_magic(header.e_ident);
	printf("  Class:                             ");
	if (header.e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (header.e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		error_exit(98, "Error: Invalid ELF class");

	printf("  Data:                              ");
	if (header.e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (header.e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		error_exit(98, "Error: Invalid ELF data encoding");

	printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            ");
	switch (header.e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		default:
			printf("<unknown: %d>\n", header.e_ident[EI_OSABI]);
			break;
	}


	printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);


	printf("  Type:                              ");
	switch (header.e_type)
	{
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		default:
			printf("<unknown: %d>\n", header.e_type);
			break;
	}

	printf("  Entry point address:               0x%x\n", (unsigned int)header.e_entry);

	close(fd);
	return (0);
}
