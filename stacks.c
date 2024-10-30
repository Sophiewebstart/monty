#include "monty.h"

/**
  * main - start of program
  * @argv: argument list
  * @argc: argument count
  * Return: Always 0
  **/
int main(int argc, char **argv)
{
	FILE *my_file;
	char *line = NULL;
	char *opcode;
	char *arg_op;
	size_t len = 0;
	unsigned int line_num = 0;
	stack_t *head = NULL;

	if (argc != 2)
		my_err(1);

	my_file = fopen(argv[1], "r");
	if (my_file == NULL)
		my_err(2, argv[1]);

	for (line_num = 1; getline(&line, &len, my_file) != -1; line_num++)
	{
		opcode = strtok(line, " \n\t");
		arg_op = strtok(NULL, " \t\n");

		if (opcode == NULL || opcode[0] == '#')
		{
			continue;
		}

	execute(opcode, arg_op, &head, line_num);
	}

	free(line);
	fclose(my_file);
	__free(head);
	return (0);
}

/**
 * execute - Executes the opcode and calls the corresponding function.
 * @opcode: The opcode string (e.g., "push", "pall").
 * @arg_op: The argument to the opcode
 * @head: Pointer to the top of the stack
 * @line_num: line number
 */
void execute(char *opcode, char *arg_op, stack_t **head, unsigned int line_num)
{
	instruction_t list_func[] = {
		{"push", push},
		{NULL, NULL}
	};
	int i = 0;

	while (list_func[i].opcode)
	{
		if (strcmp(opcode, list_func[i].opcode) == 0)
		{
			if (strcmp(opcode, "push") == 0)
			{
				if (arg_op == NULL || !a_num(arg_op))
				{
					my_err(5, line_num);
				}
			push(head, line_num);
		}
		else
		{
			list_func[i].f(head, line_num);
		}
		return;
		}
		i++;
	}

	my_err(3, line_num, opcode);
}

/**
  * make_node - this creates a node
  * @num: Number in the node
  * Return: On success, a pointer to the node. Otherwise NULL
  **/
stack_t *make_node(int num)
{
	stack_t *n_node;

	n_node = malloc(sizeof(stack_t));
	if (!n_node)
		my_err(4);

	n_node->next = NULL;
	n_node->prev = NULL;
	n_node->n = num;
	return (n_node);
}
