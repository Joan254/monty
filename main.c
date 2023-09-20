#include "monty.h"

global_t glovar;

/**
 * free_glovar - frees the global variables
 *
 * Return: no return
 */
void free_glovar(void)
{
	free_dlistint(glovar.head);
	free(glovar.buffer);
	fclose(glovar.fd);
}

/**
 * start_glovar - initializes the global variables
 *
 * @fd: file descriptor
 * Return: no return
 */
void start_glovar(FILE *fd)
{
	glovar.lifo = 1;
	glovar.cont = 1;
	glovar.arg = NULL;
	glovar.head = NULL;
	glovar.fd = fd;
	glovar.buffer = NULL;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	start_glovar(fd);
	nlines = getline(&glovar.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = _strtoky(glovar.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				fprintf(stderr, "L%u: ", glovar.cont);
				fprintf(stderr, "unknown instruction %s\n", lines[0]);
				free_glovar();
				exit(EXIT_FAILURE);
			}
			glovar.arg = _strtoky(NULL, " \t\n");
			f(&glovar.head, glovar.cont);
		}
		nlines = getline(&glovar.buffer, &size, fd);
		glovar.cont++;
	}

	free_glovar();

	return (0);
}
