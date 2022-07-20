#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <readline/readline.h>

int main(void)
{
	char *result;

	result = readline("prompt: ");
	if (result != NULL && strncmp(result, "echo", 4) == 0)
	{
		if (isspace(result[4]))
			printf("%s", result + 5);
		printf("\n");
	}
    if (result != NULL)
        free(result);
	return (0);
}
