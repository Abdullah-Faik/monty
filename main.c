#include "main.h"

/**
 * main - Entry point of the Monty interpreter program
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	int line_num = 0;
	FILE *file = NULL;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, ERR_USAGE);
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, ERR_OPEN, argv[1]);
		exit(EXIT_FAILURE);
	}
	read_file(file, &stack);

	fclose(file);
	return (EXIT_SUCCESS);
}

/**
 * read_file - Reads the Monty bytecode file and executes the instructions
 * @file: Pointer to the bytecode file
 * @stack: Double pointer to the stack
 */
void read_file(FILE *file, stack_t **stack)
{
	glob_lin = 0;
	char line[1024];
	char *opcode, *value;
	char *delim = " \n\t\r";

	while (fgets(line, 1024, file))
	{
		glob_lin++;
		opcode = strtok(line, delim);
		if (opcode == NULL || strncmp(opcode, "#", 1) == 0)
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			value = strtok(NULL, delim);
			if (value == NULL || is_number(value) == 0)
			{
				fprintf(stderr, ERR_PUSH, glob_lin);
				exit(EXIT_FAILURE);
			}
			glob_val = atoi(value);
		}
		operationfunc(opcode, glob_lin, &stack);
	}
}
