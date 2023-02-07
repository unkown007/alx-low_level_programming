#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <elf.h>

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

int is_Elf64(Elf64_Ehdr eh)
{
	if (!strncmp((char *)eh.e_ident, "\177ELF", 4))
		return (1);
	return (0);
}

void print_elf_header64(Elf64_Ehdr elf_header)
{
	char *s, addr[10];
	int i;

	printf("  Magic:   ");
	s = (char *) elf_header.e_ident;
	for (i = 0; i < 16; i++)
	{
		printf("%02x", *(s + i));
		if (i != 15)
			putchar(' ');
	}
	putchar('\n');
	printf("  Class:\t\t\t     ");
	switch(elf_header.e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("INVALID CLASS\n");
			break;
	}
	printf("  Data:\t\t\t\t     ");
	switch(elf_header.e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("INVALID Format\n");
			break;
	}
	printf("  Version:\t\t\t     ");
	switch(elf_header.e_ident[EI_VERSION])
	{
		case EV_NONE:
			printf("Invalid version\n");
			break;
		case EV_CURRENT:
			printf("1 (current)\n");
			break;
	}
	printf("  OS/ABI:\t\t\t     ");
	switch(elf_header.e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("HP-UX\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - GNU\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solares\n");
			break;
		case ELFOSABI_AIX:
			printf("IBM AIX\n");
			break;
		case ELFOSABI_IRIX:
			printf("SGI Irix\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("Compaq TRU64 UNIX\n");
			break;
		case ELFOSABI_MODESTO:
			printf("Novell Modesto\n");
			break;
		case ELFOSABI_OPENBSD:
			printf("OpenBSD\n");
			break;
		case ELFOSABI_ARM_AEABI:
			printf("ARM EABI\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone (embedded app\n)");
			break;
		default:
			printf("<unknown %d>\n", elf_header.e_ident[EI_OSABI]);
			break;
	}
	printf("  ABI Version:\t\t\t     %d\n", elf_header.e_ident[EI_ABIVERSION]);
	printf("  Type:\t\t\t\t     ");
	switch(elf_header.e_type)
	{
		case ET_NONE:
			printf("N/A (0x0)\n");
			break;
		case ET_REL:
			printf("Relocatable\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		default:
			printf("<unknown: %d>\n", elf_header.e_type);
			break;
	}
	sprintf(addr, "%lx", elf_header.e_entry);
	printf("  Entry point address:\t\t     0x%s\n", addr + 5);
}

int32_t main(int argc, char *argv[])
{
	int32_t fd;
	Elf64_Ehdr eh;

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
	read_elf_header64(fd, &eh);
	if (!is_Elf64(eh))
	{
		fprintf(stderr, "Error: %s is not an ELF file\n", argv[1]);
		exit(98);
	}
	printf("ELF Header:\n");
	if (is_Elf64(eh))
	{
		print_elf_header64(eh);
	}
	return (0);
}
