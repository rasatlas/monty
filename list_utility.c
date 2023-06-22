#include "monty.h"
​
/**
 * create_node_stackfirst - create a node stack.
 * @stack: A pointer to top and bottom stack.
 * @n: the value
 * Return: the node
 */

stack_t *create_node_stackfirst(stack_t **stack, int n)
{
	stack_t *newnode_stack;

	if (stack == NULL)
		return (NULL);
	newnode_stack = malloc(sizeof(stack_t));
	if (newnode_stack == NULL)
		stderr_malloc();
	newnode_stack->n = n;
	newnode_stack->next = *stack;
	newnode_stack->prev = NULL;
	*stack = newnode_stack;
	return (newnode_stack);
}

/**
 * create_node_stackend - create a node stack at end.
 * @stack: A pointer to top and bottom stack.
 * @n: the value
 * Return: the node
 */

stack_t *create_node_stackend(stack_t **stack, int n)
{
	stack_t *newnode_stack;
	stack_t *temp;

	if (stack == NULL)
		return (NULL);
	newnode_stack = malloc(sizeof(stack_t));
	if (newnode_stack == NULL)
		stderr_malloc();
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newnode_stack;
	newnode_stack->n = n;
	newnode_stack->prev = temp;
	newnode_stack->next = NULL;
	return (newnode_stack);
}
