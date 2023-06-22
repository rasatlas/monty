#include "monty.h"

/**
 * array_len - calculates the array of a token.
 * Return: Lenght of the token.
 */

unsigned int array_len(void)
{
	unsigned int token_len = 0;

	while (globalvar.token2[token_len])
		token_len++;
	return (token_len);
}

/**
 * tokerr - makes the last element of instructions as error code.
 * @error_status: type int where the error is saved as srt.
 */

void tokerr(int error_status)
{
	int token_len = 0, i = 0;
	char *exit_str = NULL;
	char *new_token = NULL;

	token_len = array_len();
	new_token = malloc(sizeof(char *) * (token_len + 2));
	if (!globalvar.token2)
	{
		stderr_malloc();
		return;
	}
	while (i < token_len)
	{
		new_token[i] = globalvar.token2[i];
		i++;
	}
	exit_str = get_int(error_status);
	if (!exit_str)
	{
		free(globalvar.token2);
		stderr_malloc();
		return;
	}
	free(globalvar.token2);
	globalvar.token2 = new_token;
}

/**
 * _isdigit - Entry point
 *
 * Return: if is digit  or not, return 1 else 0
 */

int _isdigit(void)
{
	int i = 0;

	if (globalvar.token2[0] == '-' || globalvar.token2[0] == '+')
		i++;
	while (globalvar.token2[i])
	{

		if (isdigit(globalvar.token2[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

/**
 * get_int - get char pointer to new str with int
 * @num: number to convert to string
 * Return: char pointer converted as null if fails and malloc.
 */

char *get_int(int num)
{
	long num_v = 0;
	unsigned int tmp;
	int len = 0;
	char *ret;

	tmp = abs_m(num);
	len = len_buff_uint(tmp, 10);

	if (num < 0 || num_v < 0)
		len++;
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);

	full_buff(tmp, 10, ret, len);
	if (num < 0 || num_v < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * abs_m - abs value of int
 * @i: integer to get absolute value of
 * Return: unsigned int of i
 */

unsigned int abs_m(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}
