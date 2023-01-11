SRC_DIR		= src
OBJ_DIR		= obj
SRCS		= main.c parsing/parsing.c parsing/map_error_part1.c parsing/map_error_part2.c  \
				init_mini_map.c draw_lines.c keypress.c tools.c parsing/error_message_handling.c


SRC			= $(addprefix src/, $(SRCS))
OBJS		= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
D_OBJS		= mkdir -p $(@D)
CC			= clang
CFLAGS		= -g -Wall -Wextra -Werror
NAME		= cub3D
RM			= rm -f
RM_OBJ		= rm -rf
LIBFT		= libft/libft.a
MLX			= mlx_linux/libmlx.a

all:		$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c	
			@$(D_OBJS)
			@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c -o $@ $<

$(LIBFT):
			@make -s -C libft/

$(MLX):	
			@make -s -C mlx_linux/

$(NAME): 	$(OBJS) $(LIBFT) $(MLX)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
			@echo "\033[1;92m\nmake completed\n\033[0m"

clean:
			@$(RM_OBJ) $(OBJ_DIR)
			@make -s fclean -C libft/
			@make -s clean -C mlx_linux/
			@echo "\033[1;93m\nmake clean completed\n\033[0m"

fclean:	
			@$(RM_OBJ) $(OBJ_DIR)
			@$(RM) $(NAME)
			@make -s fclean -C libft/
			@make -s clean -C mlx_linux/
			@echo "\033[1;91m\nmake fclean completed\n\033[0m"

re:			fclean all

.PHONY:		all clean fclean re
