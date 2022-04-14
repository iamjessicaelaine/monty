#include "monty.h"

/**
 * main - interpreter for monty bytecode files
 * @argc: size of argv
 * @argv: pointer to array of arguments passed to main
 * Return: 0 for success of -1 for error or failure
 */

int main(int argc, char *argv[])
{
	unsigned int line_number = 0; /* tracks line # in bytecode file */
	const char *filename = argv[1]; /* path & name to bytecode file */
	FILE *openedfile; /* pointer to first character in opened file */
	char *opcode = NULL; /* operation code token */
	char *linebuffer = NULL; /* stores each line of file */
	ssize_t linechars = 0; /* number or characters in each line of file */
	size_t linelen = 0; /* auto alloc mem in getline call */
	char *value = NULL; /* capture token that follows opcode */
	int valueint; /* conversion of value string to an integer */

	if (filename == NULL || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openedfile = fopen(filename, "r"); /* open file for read only */
	if (openedfile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (linechars != -1) /* loop to read file line by line */
	{
		linechars = getline(&linebuffer, &linelen, openedfile);
		line_number++;
		opcode = strtok(linebuffer, " \t\r\n\v\f");
		if (opcode != NULL)
		{
			value = strtok(NULL, " \t\r\n\v\f");
			if (value != NULL)
			{
				valueint = atoi(value);
			}
		}
	}
}
