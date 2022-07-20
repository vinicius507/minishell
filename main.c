#include <stdio.h>
#include <string.h>
#include <readline/readline.h>

int main(int argc, char **argv)
{
	char *result;

	result = readline("prompt: ");
	if (strcmp(result, "echo") == 0)
	{
		printf("\n");
	}
	return (0);
}
