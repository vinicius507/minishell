#include <libft.h>

int ft_isspace(int c)
{
    return (c == ' ' || c == '\t' || c == '\r' || c == '\f' || c == '\n' || c == '\v');
}