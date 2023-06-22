#include "monty.h"

/**
 * len_buff_uint - length of buff for an unsigned int
 * @num: number to get length needed for
 * @base: base of number representation used by buffer
 * Return: int of len of buff
 */

int len_buff_uint(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * full_buff - complete buff with numbers
 * @num: number to convert to str
 * @base: b number
 * @buff: buffer to be completed
 * @buff_size: size of buffer
 * Return: void.
 */

void full_buff(unsigned int num, unsigned int base, char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buff[i] = rem + 87;
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}
