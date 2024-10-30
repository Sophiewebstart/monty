#include "monty.h"

/**
  * push - pushes an element to the stack
  * @head: pointer to the top of stack
  * @line_num: line number in monty
  * @element: element to be pushed
  **/
void push(stack_t **head, unsigned int line_num)
{
	int element = 0;
	char *args = 0;
	stack_t *temp_node = make_node(element);

	if (!a_num(args))
	{
		my_err(5, line_num);
	}

	element = atoi(args);

	if (*head != NULL)
	{
		temp_node->next = *head;
		(*head)->prev = temp_node;
	}
	*head = temp_node;
}

/**
  * a_num - checks if string is a valid integer
  * @str: the string
  * Return: 1 if string is valid , otherwise 0
  **/
int a_num(char *str)
{
	if (str == NULL)
		return (0);

	if (*str == '-' || *str == '+')
		str++;

	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}
