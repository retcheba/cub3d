SRC_DIR		= src
OBJ_DIR		= obj
SRCS		= ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_putchar.c \
	ft_printf/ft_putnbr.c \
	ft_printf/ft_putstr.c \
	ft_printf/ft_putnbr_pos.c \
	ft_printf/ft_puthexa.c \
	ft_printf/ft_putptr.c \
	ft_printf/ft_puthexa_maj.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c
SRC			= $(addprefix src/, $(SRCS))
OBJS		= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
D_OBJS		= mkdir -p $(@D)
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
NAME		= libft.a
RM			= rm -f
RM_OBJ		= rm -rf

all:		${NAME}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
			@$(D_OBJS)
			$(CC) $(CFLAGS) -c -o $@ $<

$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:
			${RM_OBJ} $(OBJ_DIR)

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
