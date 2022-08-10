NAME = libft.a
CC = gcc
AR = ar rcs
RM = /bin/rm -f
CFLAGS = -Wall -Wextra -Werror

BUFFER_SIZE = 8
GNL_FLAGS = -D BUFFER_SIZE=$(BUFFER_SIZE)

INCLUDESDIR = ./includes
SRCDIR = ./src
OBJDIR = ./build

INCLUDES = -I$(INCLUDESDIR)
SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
	   ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
	   ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
	   ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
	   ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	   ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
	   ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	   ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c \
	   ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	   ft_lstclear.c ft_lstiter.c ft_lstmap.c get_next_line.c \
	   ft_strnjoin.c ft_putchar.c ft_putstr.c ft_putnbr.c \
	   ft_itoa_base.c ft_ltoa.c ft_lltoa.c ft_ltoa_base.c \
	   ft_lltoa_base.c ft_memjoin.c ft_uitoa.c ft_ultoa.c \
	   ft_ulltoa.c ft_uitoa_base.c ft_striter.c ft_ultoa_base.c \
	   ft_ulltoa_base.c ft_atold.c ft_strcmp.c ft_ldtoa.c \
	   ft_abs.c ft_atoll.c ft_isspace.c ft_string_array.c

FT_PRINTFDIR = $(SRCDIR)/ft_printf
FT_PRINTFSRCS = apply.c apply_char.c apply_hexa.c apply_int.c \
				apply_literal.c apply_ptr.c apply_str.c apply_uint.c \
				arg_parser.c flags_parser.c format_char.c format_current.c \
				format_hexa.c format_int.c format_literal.c format_ptr.c \
				format_str.c format_uint.c ft_asprintf.c ft_dprintf.c \
				ft_printf.c ft_sprintf.c length_parser.c precision_parser.c \
				utils.c width_parser.c

OBJS := $(addprefix $(OBJDIR)/,$(SRCS:%.c=%.o)) $(addprefix $(OBJDIR)/,$(FT_PRINTFSRCS:%.c=%.o))
SRCS := $(addprefix $(SRCDIR)/,$(SRC)) $(addprefix $(FT_PRINTFDIR)/,$(FT_PRINTFSRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

$(OBJDIR)/%.o: $(FT_PRINTFDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

$(OBJDIR)/get_next_line.o: $(SRCDIR)/get_next_line.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(GNL_FLAGS) $< -c -o $@

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME) $(NAME:.a=.so)

re: fclean all

so: $(OBJS)
	$(CC) $(CFLAGS) -shared -fpic $^ -o $(NAME:.a=.so)

.PHONY: all clean fclean re so
