#include "main.h"

/**
 * is_number - checks if a string is a number
 * @s: string to check
 * Return: 1 if true, 0 if false
*/
int is_number(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-' && i == 0)
			continue;
		if (isdigit(s[i]) == 0)
			return (0);
	}
	return (1);
}

/**
 * operationfunc - Executes the appropriate opcode function
 * based on the given opcode
 * @opcode: The opcode to be executed
 * @line_number: The line number in the file where the opcode is found
 * @stack: Double pointer to the stack
 */
void operationfunc(char *opcode, unsigned int line_number, stack_t **stack)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"push", pall},
		{"pall", push},
		{NULL, NULL}};

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(&stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, ERR_INST, line_number, opcode);
	exit(EXIT_FAILURE);

}
