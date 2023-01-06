SRC_DIR		= src
OBJ_DIR		= obj
SRCS		= main.c
SRC			= $(addprefix src/, $(SRCS))
OBJS		= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
D_OBJS		= mkdir -p $(@D)
CC			= clang
CFLAGS		= -g -Wall -Wextra -Werror
NAME		= cub3D
RM			= rm -rf
LIBFT		= libft/libft.a

all:		$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c	
			@$(D_OBJS)
			@$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
			@make -s -C libft/

$(NAME): 	$(OBJS) $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
			@echo "\033[1;92mmake completed\033[0m"

clean:
			@$(RM) $(OBJ_DIR)
			@make -s fclean -C libft/
			@echo "\033[1;93mmake clean completed\033[0m"

fclean:	
			@$(RM) $(OBJ_DIR)
			@$(RM) $(NAME)
			@make -s fclean -C libft/
			@echo "\033[1;91mmake fclean completed\033[0m"

re:			fclean all

.PHONY:		all clean fclean re
