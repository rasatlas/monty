#ifndef MONTY_H
#define MMONTY_H

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define QUEUE 1
#define STACK 0
#define DELIM " \n\t\a\b"

/**
 * globales_s - struct with variable globals
 * @token2: integer
 * @fd: points to the previous element of the stack (or queue)
 * @line_buf: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct globales_s
{
	char *token2;
	FILE *fd;
	char *line_buf;

} globales_t;

extern globales_t globalvar;

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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* opcodes_1.c */

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/* opcodes_2.c */

void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);

/* opcodes_3.c */

void div_m(stack_t **stack, unsigned int line_number);
void mod_m(stack_t **stack, unsigned int line_number);
void pstr_t(stack_t **stack, unsigned int line_number);
void rotrl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/* list_utility.c */

stack_t *create_node_stackfirst(stack_t **stack, int n);
stack_t *create_node_stackend(stack_t **stack, int n);
stack_t *add_dnodeint(stack_t **head, int n);

/* stack.c */

int create_node_stack(stack_t **stack);
void free_node_stack(stack_t **stack);
int check_opcode(stack_t *stack);

/* opcodes_stderror.c */

void stderr_usage(void);
void stderr_fopen(char *filename);
void stderr_malloc(void);
void stderr_int(unsigned int line_number);
void stderr_unknown(char *token, unsigned int line_number);

/* opcodes_error */

void pop_e(unsigned int line_number);
void pint_e(unsigned int line_number);
void op_e(unsigned int line_number, char *op);
void pchar_e(unsigned int line_number, char *msg);
void div_e(unsigned int line_number);

/* memory_utility.c */

void free_dlistint(stack_t *stack);
void free_globalvars(void);

/* utility_1.c */
int _isdigit(void);
char *get_int(int num);
unsigned int abs_m(int i);
int len_buff_uint(unsigned int num, unsigned int base);
void full_buff(unsigned int num, unsigned int base, char *buff, int buff_size);

/* utility_2.c */

unsigned int array_len(void);
void tokerr(int error_status);
int _isdigit(void);
char *get_int(int num);
unsigned int abs_m(int i);

/* utility_3.c */

int len_buff_uint(unsigned int num, unsigned int base);
void full_buff(unsigned int num, unsigned int base, char *buff, int buff_size);

/* opcodes_handler.c */

int get_builtin(char *token, stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
