#include "monty.h"

/**
 * my_err - Prints error messages determined by their error code.
 * @err_num: The error numbers are:
 * (1) => The user does not give any file or more than one argument
 * to the program.
 * (2) => It is not possible to open or read the file.
 * (3) => The file contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 */
void my_err(int err_num, ...)
{
	va_list args;
	char *op_code;
	int line_num;
	stack_t *head = NULL;

	va_start(args, err_num);

	switch (err_num)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(args, char *));
			break;
		case 3:
			line_num = va_arg(args, int);
			op_code = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op_code);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	__free(head);
	exit(EXIT_FAILURE);
}

