#include <libft.h>
#include <stdio.h>
#include <readline/readline.h>

int main(void)
{
	char 	*result;
	char 	print_line_break;
	size_t	string_start;

	while(1)
	{
		result = readline("prompt: ");
		if (result != NULL && ft_strcmp(result, "exit") == 0)
		{
			printf("exit\n");
			free(result);
			exit(0);
		}
		if (result != NULL && ft_strcmp(result, "pwd") == 0)
			printf("%s\n", getenv("PWD"));
		if (result != NULL && ft_strncmp(result, "echo", 4) == 0)
		{
			print_line_break = 1;
			if (ft_isspace(result[4]))
			{
				string_start = 5;
				if (ft_strncmp(result + 5, "-n", 2) == 0 && (ft_isspace(result[7]) || result[7] == '\0'))
				{
					print_line_break = 0;
					string_start += 2 + (result[7] != '\0');
				}
				printf("%s", result + string_start);
			}
			if (print_line_break == 1)
				printf("\n");
		}
		if (result != NULL)
			free(result);
	}
	return (0);
}
