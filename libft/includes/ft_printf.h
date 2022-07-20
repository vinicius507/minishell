/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 08:44:08 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/06/06 08:44:08 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

# define FT_PRINTF_ERROR -1

# ifdef __linux__
#  define NULL_STR "(nil)"
# elif defined(__APPLE__)
#  define NULL_STR "0x0"
# else
#  define NULL_STR "(null)"
# endif

/* ft_printf flags. */
typedef enum e_flags
{
	ALTERNATE		= 0b00001,
	ZERO_PAD		= 0b00010,
	LEFT_JUSTIFY	= 0b00100,
	SPACE			= 0b01000,
	PLUS			= 0b10000,
}	t_flags;

/* ft_printf length modifiers */
typedef enum e_length
{
	L_NONE,
	L_L,
	L_LL,
	L_H,
	L_HH,
}	t_length;

/* ft_printf types */
typedef enum e_types
{
	TYPE_ERROR,
	LITERAL,
	CHARACTER,
	STRING,
	POINTER,
	INTEGER,
	U_INTEGER,
	HEXA_L,
	HEXA_U
}	t_types;

typedef struct s_arg
{
	uint8_t		flags;
	int			width;
	int			precision;
	t_length	modifier;
	t_types		type;
	ssize_t		printed;
}	t_arg;

/* Write formated output to stdout. */
int		ft_printf(const char *str, ...);

/* Write formated output to stdout. */
int		ft_vprintf(const char *format, va_list ap);

/* Write formated output to specific fd. */
int		ft_dprintf(int fd, const char *format, ...);

/* Write formated output to specific fd. */
int		ft_vdprintf(int fd, const char *format, va_list ap);

/* Create formated string. */
int		ft_sprintf(char *buf, const char *format, ...);

/* Create formated string. */
int		ft_vsprintf(char *buf, const char *format, va_list ap);

/* Creates and allocates memory for a formated string. */
int		ft_vasprintf(char **buf, const char *format, va_list ap);

/* Creates and allocates memory for a formated string. */
int		ft_asprintf(char **buf, const char *format, ...);

/* Frees a pointer, if not NULL, and assigns NULL to it. */
void	safe_free(void **ptr);

/* Joins two strings and frees them */
char	*safe_join(char **s1, char **s2);

/* Parses the arguments of the current specifier. */
int		arg_parser(t_arg *arg, char **var, va_list ap);

/* Parses the flags of the current specifier. */
uint8_t	flags_parser(char **f);

/* Parses the minimum field width of the current specifier. */
int		width_parser(char **f, va_list ap);

/* Parses the precision of the current specifier. */
int		precision_parser(char **f, va_list ap);

/* Parses the length modifier of the current specifier */
uint8_t	length_parser(char **f);

/* Formats current specifier and updates buffer. */
int		format_current(t_arg *arg, char **buf, char *var, va_list ap);

/* Applies minimum field generally. */
int		apply_width(char **str, t_arg *arg);

/* Formats `int` type specifier. */
char	*format_int(t_arg *arg, va_list ap);

/* Formats `unsigned int` type specifier. */
char	*format_uint(t_arg *arg, va_list ap);

/* Formats `str` type specifier. */
char	*format_str(t_arg *arg, va_list ap);

/* Formats `char` type specifier. */
char	*format_char(t_arg *arg, va_list ap);

/* Formats `%` type specifier. */
char	*format_literal(t_arg *arg);

/* Formats `void *` type specifier. */
char	*format_ptr(t_arg *arg, va_list ap);

/* Formats `hexadecimal int` type specifier. */
char	*format_hexa(t_arg *arg, va_list ap);

/* Verifies if `int` has sign. */
int		int_has_sign(char *str);

/* Applies precision for `int` specifier. */
int		apply_precision_int(char **str, t_arg *arg);

/* Applies minimum field width for `int` specifier. */
int		apply_width_int(char **str, t_arg *arg);

/* Applies precision for `int` specifier. */
int		apply_precision_uint(char **str, t_arg *arg);

/* Applies minimum field width for `int` specifier. */
int		apply_width_uint(char **str, t_arg *arg);

/* Applies precision for `str` specifier. */
int		apply_precision_str(char **str, t_arg *arg);

/* Applies minimum field width for `char` specifier. */
int		apply_width_char(char **str, t_arg *arg);

/* Applies precision for `void *` specifier. */
int		apply_precision_ptr(char **str, t_arg *arg);

/* Applies minimum field width for `hexadecimal int` specifier. */
int		apply_width_hexa(char **str, t_arg *arg);

/* Applies precision for `hexadecimal int` specifier. */
int		apply_precision_hexa(char **str, t_arg *arg);

/* Verifies if `hexadeimal int` has 0x */
int		hexa_has_alternate(char *str);

/* Applies minimum field width for `%` specifier. */
int		apply_width_literal(char **str, t_arg *arg);

/* Prints the buffer and returns the number of printed characters. */
int		print_buffer(char **buf, t_arg *arg);

#endif
