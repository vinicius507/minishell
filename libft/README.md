# Libft

My very first library in C. Made for École 42.

Some of the functions are ~~somewhat~~ optimized, others are not. This library is meant to be used on École 42 only.

Content
---

| Part | Functions |
| :--- | ---: |
| Libc functions(Mandatory) |ft_memset, ft_bzero, ft_memcpy, ft_memccpy, ft_memmove, ft_memchr, ft_memcmp, ft_strlen, ft_strlcpy, ft_strlcat, ft_strchr, ft_strrchr, ft_strnstr, ft_strncmp, ft_atoi, ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint, ft_toupper, ft_tolower, ft_calloc, ft_strdup |
| Additional Functions(Mandatory) | ft_substr,  ft_strjoin,  ft_strtrim,  ft_split,  ft_itoa,  ft_strmapi,  ft_putchar_fd,  ft_putstr_fd,  ft_putendl_fd,  ft_putnbr_fd |
| List Functions(Bonus) | ft_lstnew,  ft_lstadd_front,  ft_lstsize,  ft_lstlast,  ft_lstadd_back,  ft_lstdelone,  ft_lstclear,  ft_lstiter,  ft_lstmap |

> Behavior of `libc` functions are defined in `man(3)`. The others are briefly mentioned below.

Makefile
---

| Command | Usage |
| :--- | ---: |
| `make` | Equivalent to `make all` and `make libft.a`. Creates the library. |
| `make clean` | Removes the object files. |
| `make fclean` | Removes the object files and the library. |
| `make re` | Invokes `fclean` rule and then `all`. |
| `make so` | Creates a dynamic library(for tests purposes). |

Behavior
---

### String Functions

| Function | Behavior |
| :--- | ---: |
| ft_substr | Allocates and returns a substring from the string `s`. The substring begins at index `start` and is of maximum size `len`. |
| ft_strjoin | Allocates and returns a new string, the concatenation of `s1` and `s2`. |
| ft_strtrim | Allocates and returns a copy of `s` with the characters specified in `set` removed from the beggining and the end. |
| ft_split | Allocates and returns an array of strings obtained by splitting `s` using the character `c` as a delimiter. The array is ended by a NULL pointer. |
| ft_itoa | Allocates and returns a string representing the integer received as an argument. |
| ft_strmapi | Applies the function `f` to each character of the string `s` to create a new string(with `malloc(3)`), resulting in successive applications of `f`. |

### File Writing Functions

| Function | Behavior |
| :--- | ---: |
| ft_putchar_fd | Outputs the character `c` to the given file descriptor `fd`. |
| ft_putstr_fd | Outputs the string `s` to the given file descriptor `fd`. |
| ft_putendl_fd | Outputs the string `s` to the given file descriptor `fd`, followed by a new line. |
| ft_putnbr_fd | Outputs the integer `n` to the given file descriptor `fd`. |

### Linked List Functions

| Function | Behavior |
| :--- | ---: |
| ft_lstnew | Allocates and returns a new list element. The variable `content` is initialized with the value of the parameter and `next` is initialized to NULL. |
| ft_lstadd_front | Adds the element `new` to the beggining of the list. |
| ft_lstadd_back | Adds the element `new` to the end of the list. |
| ft_lstsize | Counts the number of elements in a list. |
| ft_lstlast | Returns the last element of a linked list. |
| ft_lstdelone | Frees the memory of a list element, applying the function `del` to the content of the element. |
| ft_lstclear | Same as ft_lstdelone but for all elements starting in `lst`. |
| ft_lstiter | Iterates the list `lst` while applying the function `f` to each element. |
| ft_lstmap | Iterates the list `lst` while applying the function `f` to each element. Creates a new list resulting of the successive applications of the function `f`. The `del` function is used to delete the content of an element if needed. |

## Additional Functions

| Function | Behavior |
| :--- | ---: |
| get_next_line<sup>[[1]](https://github.com/vinicius507/get_next_line)</sup> | Reads a line from the given file descriptor `fd`. |

## References

1. [Get Next Line](https://github.com/vinicius507/get_next_line).
