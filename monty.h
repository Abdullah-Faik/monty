#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number, char *value);
} instruction_t;

/* error messsages*/
#define ERR_USAGE "USAGE: monty file\n"
#define ERR_OPEN "Error: Can't open file %s\n"
#define ERR_MALLOC "Error: malloc failed\n"
#define ERR_PUSH "L%d: usage: push integer\n"
#define ERR_PINT "L%d: can't pint, stack empty\n"
#define ERR_POP "L%d: can't pop an empty stack\n"
#define ERR_ADD "L%d: can't add, stack too short\n"
#define ERR_INST "L%d: unknown instruction %s\n"
#define ERR_SWAP "L%d: can't swap, stack too short\n"

/* main.c */
int main(int argc, char *argv[]);
void read_file(FILE *file, stack_t **stack);

/* helper_func.c */
void operationfunc(char *opcode, unsigned int line_number, stack_t **stack, char *value);
int is_number(char *str);
void free_stack(stack_t *stack);

/* stack_func_1*/
void push(stack_t **stack, unsigned int line_number, char *value);
void pall(stack_t **stack, unsigned int line_number, char *value);
void pint(stack_t **stack, unsigned int line_number, char *value);
void pop(stack_t **stack, unsigned int line_number, char *value);
void add(stack_t **stack, unsigned int line_number, char *value);
void swap(stack_t **stack, unsigned int line_number, char *value);
void nop(stack_t **stack, unsigned int line_number, char *value);
#endif
