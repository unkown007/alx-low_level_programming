#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <inttypes.h>
#include <elf.h>

/**
 * read_elf_header64 - read content of size Elf64_Ehdr on a file
 * @fd: file descriptor
 * @elf_header: struct to store the content of the file
 */
void read_elf_header64(int32_t fd, Elf64_Ehdr *elf_header)
{
	if (elf_header == NULL)
	{
		printf("Problem with the file\n");
		exit(97);
	}
	if (lseek(fd, (off_t)0, SEEK_SET) != (off_t)0)
	{
		printf("Error: possitioning the file\n");
		exit(98);
	}
	if (read(fd, (void *)elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		printf("Error: reading the file\n");
		exit(100);
	}
}

/**
 * read_elf_header - read content of size Elf32_Ehdr on a file
 * @fd: file descriptor
 * @elf_header: struct to store the content of the file
 */
void read_elf_header(int32_t fd, Elf32_Ehdr *elf_header)
{
	if (elf_header == NULL)
	{
		printf("Problem with the file\n");
		exit(97);
	}
	if (read(fd, (void *) elf_header, sizeof(Elf32_Ehdr)) != sizeof(Elf32_Ehdr))
	{
		printf("Error: reading the file\n");
		exit(100);
	}
}

/**
 * is_Elf - checks if the file is ELF file
 * @eh: struct to store the content of the file
 *
 * Return: 1 if success, 0 otherwise
 */
int is_Elf(Elf32_Ehdr eh)
{
	if (!strncmp((char *)eh.e_ident, "\177ELF", 4))
		return (1);
	return (0);
}

/**
 * is64Bit - checks wether if 64 bit or not
 * @eh: elf header
 *
 * Return: 1 if sucess, 0 otherwise
 */
int is64Bit(Elf32_Ehdr eh)
{
	if (eh.e_ident[EI_CLASS] == ELFCLASS64)
		return (1);
	return (0);
}

/**
 * get_elf_class - set the correct elf class output text
 * @elf_class: elf class idententy
 *
 * Return: elf class text
 */
static const char *
get_elf_class(unsigned int elf_class)
{
	static char buff[32];

	switch (elf_class)
	{
		case ELFCLASS32: return "ELF32";
		case ELFCLASS64: return "ELF64";
		default:
			snprintf(buff, sizeof(buff), "<unknown: %x>", elf_class);
			return (buff);
	}
}

/**
 * get_data_enconding - set the correct elf data enconding text
 * @encoding: elf data enconding identity
 *
 * Return: data enconding text
 */
static const char *
get_data_encoding(unsigned int encoding)
{
	static char buff[32];

	switch (encoding)
	{
		case ELFDATANONE: return "none";
		case ELFDATA2LSB: return "2's complement, little endian";
		case ELFDATA2MSB: return "2's complement, big endian";
		default:
			snprintf(buff, sizeof(buff), "<unknown: %x>", encoding);
			return (buff);
	}
}

/**
 * get_osabi_name - get OS/ABI name
 * @osabi: elf osabi identity
 *
 * Return: osabi name
 */
static const char *
get_osabi_name(unsigned int osabi)
{
	static char buff[32];

	switch (osabi)
	{
		case ELFOSABI_NONE:return "UNIX - System V";
		case ELFOSABI_HPUX:return "UNIX - HP-UX";
		case ELFOSABI_NETBSD:return "UNIX - NetBSD";
		case ELFOSABI_LINUX:return "UNIX - GNU";
		case ELFOSABI_SOLARIS:return "UNIX - Solaris";
		case ELFOSABI_AIX:return "UNIX - AIX";
		case ELFOSABI_IRIX:return "UNIX - IRIX";
		case ELFOSABI_FREEBSD:return "UNIX - FreeBSD";
		case ELFOSABI_TRU64:return "UNIX - TRU64";
		case ELFOSABI_MODESTO:return "Novell - Modesto";
		case ELFOSABI_OPENBSD:return "UNIX - OpenBSD";
		case ELFOSABI_STANDALONE:return "Standalone (embedded app)";
		default:
			snprintf(buff, sizeof(buff), "<unknown: %x>", osabi);
			return (buff);
	}
}

/**
 * get_file_type - get file type
 * @e_type: file type identity
 *
 * Return: file type name
 */
static const char *
get_file_type(uint16_t e_type)
{
	static char buff[64];

	switch (e_type)
	{
		case ET_NONE:return "NONE (None)";
		case ET_REL:return "REL (Relocatable file)";
		case ET_EXEC:return "EXEC (Executable file)";
		case ET_DYN:return "DYN (Shared object file)";
		case ET_CORE:return "CORE (Core file)";
		default:
			snprintf(buff, sizeof(buff), "<unknown>: %x", e_type);
			return (buff);
	}
}

/**
 * print_elf_header - prints a elf file's header
 * @elf_header: elf file's content
 */
void print_elf_header(Elf32_Ehdr elf_header)
{
	printf("  Class:                             %s\n",
		get_elf_class(elf_header.e_ident[EI_CLASS]));
	printf("  Data:                              %s\n",
		get_data_encoding(elf_header.e_ident[EI_DATA]));
	printf("  Version:                           %d%s\n",
		elf_header.e_ident[EI_VERSION],
		(elf_header.e_ident[EI_VERSION] == EV_CURRENT
		 ? " (current)"
		 : (elf_header.e_ident[EI_VERSION] != EV_NONE
			 ? " <unknown>"
			 : "")));
	printf("  OS/ABI:                            %s\n",
		get_osabi_name(elf_header.e_ident[EI_OSABI]));
	printf("  ABI Version:                       %d\n",
		elf_header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n",
		get_file_type(elf_header.e_type));
	printf("  Entry point address:               0x%x\n",
		elf_header.e_entry);
}

/**
 * print_elf_header64 - prints a elf file's header
 * @elf_header: elf file's content
 */
void print_elf_header64(Elf64_Ehdr elf_header)
{
	printf("  Class:                             %s\n",
		get_elf_class(elf_header.e_ident[EI_CLASS]));
	printf("  Data:                              %s\n",
		get_data_encoding(elf_header.e_ident[EI_DATA]));
	printf("  Version:                           %d%s\n",
		elf_header.e_ident[EI_VERSION],
		(elf_header.e_ident[EI_VERSION] == EV_CURRENT
		 ? " (current)"
		 : (elf_header.e_ident[EI_VERSION] != EV_NONE
			? " <unknown>"
			: "")));
	printf("  OS/ABI:                            %s\n",
		get_osabi_name(elf_header.e_ident[EI_OSABI]));
	printf("  ABI Version:                       %d\n",
		elf_header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n",
		get_file_type(elf_header.e_type));
	printf("  Entry point address:               0x%lx\n",
		elf_header.e_entry);
}

/**
 * main - display information contained in the ELF header at the start
 * of an ELF file
 * @argc: number of arguments
 * @argv: arguments of the program
 *
 * Return: Always 0 (sucess)
 */
int32_t main(int argc, char *argv[])
{
	int32_t fd;
	unsigned int i;
	Elf32_Ehdr eh;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: elf_header elf_filename\n");
		exit(98);
	}
	fd = open(argv[1], O_RDONLY | O_SYNC);
	if (fd < 0)
	{
		fprintf(stderr, "Error: Unable to open %s\n", argv[1]);
		exit(98);
	}
	read_elf_header(fd, &eh);
	if (!is_Elf(eh))
	{
		fprintf(stderr, "%s: Error: Not an ELF file - "
			"it has the wrong magic bytes at the start\n", argv[0]);
		exit(98);
	}
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%2.2x", eh.e_ident[i]);
		if (i != EI_NIDENT - 1)
			putchar(' ');
	}
	putchar('\n');
	if (is64Bit(eh))
	{
		Elf64_Ehdr eh64;

		read_elf_header64(fd, &eh64);
		print_elf_header64(eh64);
	} else
		print_elf_header(eh);
	return (0);
}
