#include "monty.h"

/**
 * __atoi - this function converts a string to an integer
 * @string: string to be corrected
 *
 * Return: integer value of converted string
 */
int __atoi(const char *string)
{
	int sign = 1;
	int value = 0;

	while (*string++)
	{

		if (*string == '-')
			sign = -1;

		else if (*string >= '0' && *string <= '9')
			value = (value * 10) + (*string - '0');

		else if (value > 0)
			break;
	}

	return (value * sign);
}

/**
 * __free - this function frees the nodes in a stack
 */
void __free(stack_t *head)
{
	stack_t *tmp_mem;

	if (head == NULL)
	{
		return;
	}

	while (head != NULL)
	{
		tmp_mem = head;
		head = head->next;
		free(tmp_mem);
	}
}
