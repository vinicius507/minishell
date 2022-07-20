#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <readline/readline.h>

int main(void)
{
	char 	*result;
	char 	print_line_break;
	size_t	string_start;

	result = readline("prompt: ");
	if (result != NULL && strncmp(result, "echo", 4) == 0)
	{
		print_line_break = 1;
		if (isspace(result[4]))
		{
			string_start = 5;
			if (strncmp(result + 5, "-n", 2) == 0 && (isspace(result[7]) || result[7] == '\0'))
			{
				print_line_break = 0;
				string_start += 3;
			}
			printf("%s", result + string_start);
		}
		if (print_line_break == 1)
			printf("\n");
	}
	if (result != NULL)
		free(result);
	return (0);
}
