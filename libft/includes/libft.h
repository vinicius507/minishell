/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:02:26 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/10 14:37:29 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* Sets `n` bytes of `s` to `c`. */
void		*ft_memset(void *s, int c, size_t n);

/* Sets `n` bytes of `s`to `\0`. */
void		ft_bzero(void *s, size_t n);

/* Copies `n` bytes of `src` to `dest`. Overlapping behavior is undefined. */
void		*ft_memcpy(void *dest, const void *src, size_t n);

/* Copies a max of `n` bytes of `src` to `dest`, stopping if it copies the
 * byte  `c`. Overlapping behavior is undefined. */
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);

/* Copies `n` bytes from `src` to `dest`. Overlapping behavior is defined. */
void		*ft_memmove(void *dest, const void *src, size_t n);

/* Finds the byte `c` in `s`. */
void		*ft_memchr(const void *s, int c, size_t n);

/* Compares `n` bytes from `s1` and `s2`. */
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/* Joins scetors of memory m1 and m2 */
void		*ft_memjoin(const void *m1, const void *m2,
				size_t size1, size_t size2);

/* Gets the size of a string. */
size_t		ft_strlen(const char *str);

/* Copies up to `size - 1` characters from `src` to `dest`, NUL-terminating the
 * result. */
size_t		ft_strlcpy(char *dest, const char *src, size_t size);

/* Appends up to `size - strlen(dest) - 1` bytes from `src` to `dest`. */
size_t		ft_strlcat(char *dest, const char *src, size_t size);

/* Finds the first occurrence character `c` in the string `s`. */
char		*ft_strchr(const char *s, int c);

/* Finds the last occurrence character `c` in the string `s`. */
char		*ft_strrchr(const char *s, int c);

/* Finds the first occurrence of the string `little` in the string `big`, where
 * no more than `len` characters are searched. */
char		*ft_strnstr(const char *big, const char *little, size_t len);

/* Compares `n` characters from `s1` and `s2`, returns a non-zero value if the
 * strings are different. */
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/* Compares `s1` and `s2`, returns a non-zero value if the strings are
 * different. */
int			ft_strcmp(const char *s1, const char *s2);

/* Converts the initial portion of the string `nptr` to an `int`. */
int			ft_atoi(const char *nptr);

/* Converts the initial portion of the string `nptr` to an `int`. */
long long	ft_atoll(const char *nptr);

/* Converts the initial portion of the string `nptr` to a `long double`. */
long double	ft_atold(const char *nptr);

/* Verifies if `c` is a alphabetic character of the ASCII table */
int			ft_isalpha(int c);

/* Verifies if `c` is a numeric character of the ASCII table */
int			ft_isdigit(int c);

/* Verifies if `c` is a numeric or alphabetic character of the ASCII table */
int			ft_isalnum(int c);

/* Verifies if `c` is an ASCII character. */
int			ft_isascii(int c);

/* Verifies if `c` is a printable ASCII character. */
int			ft_isprint(int c);

/* Verifies if `c` is a space. */
int			ft_isspace(int c);

/* If `c` is a lowercase ASCII character, it returns it's uppercase equivalent.
 * */
int			ft_toupper(int c);

/* If `c` is a uppercase ASCII character, it returns it's lowercase equivalent.
 * */
int			ft_tolower(int c);

/* Allocates `nmemb * size` bytes of memory. The memory is set to zero. */
void		*ft_calloc(size_t nmemb, size_t size);

/* Duplicates and returns an allocated duplicate of `s`. */
char		*ft_strdup(const char *s);

/* Allocates and returns a substring from the string `s`. The substring begins
 * at index `start` and is of maximum size `len`. */
char		*ft_substr(const char *s, unsigned int start, size_t len);

/* Allocates and returns a new string, which is the result of the concatenation
 * of `s1` and `s2`. */
char		*ft_strjoin(const char *s1, const char *s2);

/* Allocates and returns a new string, which is the result of the concatenation
 * of `s1` and `s2`. */
char		*ft_strnjoin(const char *s1, const char *s2, size_t n);

/* Allocates and returns a copy of `s1` with the characters specified in `set`
 * removed from the beginning and the end of the string. */
char		*ft_strtrim(const char *s1, const char *set);

/* Allocates and returns an array of strings obtained by splitting `s` using
 * the character `c` as a delimiter. The array must be ended by a NULL pointer.
 * */
char		**ft_split(const char *s, char c);

/* Allocates and returns a string representing the integer received as an
 * argument. */
char		*ft_itoa(int n);

/* Allocates and returns a string representing the long integer received as an
 * argument. */
char		*ft_ltoa(long int n);

/* Allocates and returns a string representing the long long integer received
* as an argument. */
char		*ft_lltoa(long long int n);

/* Allocates and returns a string representing the long double received as an
 * argument up to a certain precision. */
char		*ft_ldtoa(long double n, size_t precision);

/* Allocates and returns a string representing the unsigned integer received as
 * an argument. */
char		*ft_uitoa(unsigned int n);

/* Allocates and returns a string representing the unsigned long integer
 * received as an argument. */
char		*ft_ultoa(unsigned long int n);

/* Allocates and returns a string representing the unsigned long long integer
 * received as an argument. */
char		*ft_ulltoa(unsigned long long int n);

/* Allocates and returns a string representing the integer received as an
 * argument in a specific base. */
char		*ft_itoa_base(int n, char *base);

/* Allocates and returns a string representing the long integer received as an
 * argument in a specific base. */
char		*ft_ltoa_base(long int n, char *base);

/* Allocates and returns a string representing the long long integer received
* as an argument in a specific base. */
char		*ft_lltoa_base(long long int n, char *base);

/* Allocates and returns a string representing the unsigned integer received as
 * an argument in a specific base. */
char		*ft_uitoa_base(unsigned int n, char *base);

/* Allocates and returns a string representing the unsigned long integer
 * received as an argument in a specific base. */
char		*ft_ultoa_base(unsigned long int n, char *base);

/* Allocates and returns a string representing the unsigned long long integer
 * received as an argument in a specific base. */
char		*ft_ulltoa_base(unsigned long long int n, char *base);

/* Applies the function `f` to each character of the string `s` to create a new
 * string resulting from successive applications of `f`. */
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));

/* Applies the function `f` to each character of the string `s` to create a new
 * string resulting from successive applications of `f`. */
char		*ft_striter(const char *s, int (*f)(int));

/* Outputs the character `c` to the given file descriptor. */
void		ft_putchar_fd(char c, int fd);

/* Outputs the string `s` to the given file descriptor. */
void		ft_putstr_fd(char *s, int fd);

/* Outputs the string `s` to the given file descriptor, followed by a newline.
 * */
void		ft_putendl_fd(char *s, int fd);

/* Outputs the integer `n` to the given file descriptor. */
void		ft_putnbr_fd(int s, int fd);

/* Outputs the character `c` to stdout. */
void		ft_putchar(char c);

/* Outputs the string `s` to the stdout. */
void		ft_putstr(char *s);

/* Outputs the integer `n` to the stdout. */
void		ft_putnbr(int s);

/* Allocates and returns a new element. The variable `content` is initialized
 * with the value of the parameter `content`. The variable `next` is
 * initialized to NULL. */
t_list		*ft_lstnew(void *content);

/* Adds the element `new` at the beginning of the list. */
void		ft_lstadd_front(t_list **lst, t_list *new);

/* Counts the number of elements in a list. */
int			ft_lstsize(t_list *lst);

/* Returns the last element of the list. */
t_list		*ft_lstlast(t_list *lst);

/* Adds the element `new` at the end of the list. */
void		ft_lstadd_back(t_list **lst, t_list *new);

/* Takes as parameter an element and frees the memory of the element's content
 * using the function `del` as a parameter and free the element. The memory of
 * `next` is not be freed. */
void		ft_lstdelone(t_list *lst, void (*del)(void *));

/* Deletes and frees the given element and every successor of that element,
 * using the function `del`. Finally, the pointer to the list is set to NULL.
 * */
void		ft_lstclear(t_list **lst, void (*del)(void *));

/* Iterates the list `lst` and applies the function `f` to the content of each
 * element. */
void		ft_lstiter(t_list *lst, void (*f)(void *));

/* Iterates the list `lst` and applies the function `f` to the content of each
 * element. Creates a new list resulting of the successive applications of the
 * function `f`. The `del` function is used to delete the content of an element
 * if needed. */
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

typedef enum e_gnlstatus
{
	GNL_ERROR = -1,
	END_OF_FILE,
	NEWLINE,
}	t_gnlstatus;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# if BUFFER_SIZE <= 0
#  error BUFFER_SIZE needs to be a positive number.
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 64
# endif

/* Reads a line from the given file descriptor `fd`. */
int			get_next_line(int fd, char **line);

/* Write formated output to stdout. */
int			ft_printf(const char *str, ...);

/* Write formated output to stdout. */
int			ft_vprintf(const char *format, va_list ap);

/* Write formated output to specific fd. */
int			ft_dprintf(int fd, const char *format, ...);

/* Write formated output to specific fd. */
int			ft_vdprintf(int fd, const char *format, va_list ap);

/* Create formated string. */
int			ft_sprintf(char *buf, const char *format, ...);

/* Create formated string. */
int			ft_vsprintf(char *buf, const char *format, va_list ap);

/* Creates and allocates memory for a formated string. */
int			ft_vasprintf(char **buf, const char *format, va_list ap);

/* Creates and allocates memory for a formated string. */
int			ft_asprintf(char **buf, const char *format, ...);

/* Returns the absolute value of a number. */
uint		ft_abs(int n);

void	ft_free_string_array(char **str_arr);

#endif
