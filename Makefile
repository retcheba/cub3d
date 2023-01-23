OBJ_DIR		= obj
SRC_DIR		= src
SRCS		= main.c init_and_close.c mini_map.c ray_caster.c ray_caster_utils.c \
				background_map.c get_color_texture.c keypress1.c keypress2.c tools.c gun.c \
				parsing.c parsing_utils.c error_part/check_scene_errors.c \
				error_part/check_map_errors.c error_part/error_message_handling.c \
				error_part/check_color_errors.c error_part/colors.c \
				error_part/check_closed_map.c error_part/get_map_elements.c \
				error_part/check_surrounded.c
SRC			= $(addprefix src/, $(SRCS))
OBJS		= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
D_OBJS		= mkdir -p $(@D)

OBJ_BONUS_DIR	= obj_bonus
SRC_BONUS_DIR	= src_bonus
SRCS_BONUS		= main_bonus.c init_and_close_bonus.c mini_map_bonus.c ray_caster_bonus.c \
					ray_caster_utils_bonus.c background_map_bonus.c get_color_texture_bonus.c \
					keypress1_bonus.c keypress2_bonus.c tools_bonus.c gun_bonus.c \
					parsing_bonus.c parsing_utils_bonus.c error_part/check_scene_errors_bonus.c \
					error_part/check_map_errors_bonus.c error_part/error_message_handling_bonus.c \
					error_part/check_color_errors_bonus.c error_part/colors_bonus.c \
					error_part/check_closed_map_bonus.c error_part/get_map_elements_bonus.c \
					error_part/check_surrounded_bonus.c
SRC_BONUS		= $(addprefix src_bonus/, $(SRCS_BONUS))
OBJS_BONUS		= $(SRC_BONUS:$(SRC_BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)
D_OBJS_BONUS	= mkdir -p $(@D)

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

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c	
			@$(D_OBJS_BONUS)
			@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c -o $@ $<

$(LIBFT):
			@make -s -C libft/

$(MLX):	
			@make -s -C mlx_linux/

$(NAME): 	$(OBJS) $(LIBFT) $(MLX)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
			@echo "\033[1;92m\nmake completed\n\033[0m"

clean:
			@$(RM_OBJ) $(OBJ_DIR) $(OBJ_BONUS_DIR)
			@make -s fclean -C libft/
			@make -s clean -C mlx_linux/
			@echo "\033[1;93m\nmake clean completed\n\033[0m"

fclean:	
			@$(RM_OBJ) $(OBJ_DIR) $(OBJ_BONUS_DIR)
			@$(RM) $(NAME)
			@make -s fclean -C libft/
			@make -s clean -C mlx_linux/
			@echo "\033[1;91m\nmake fclean completed\n\033[0m"

re:			fclean all

bonus:		$(OBJS_BONUS) $(LIBFT) $(MLX)
			@$(RM) $(NAME)
			@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
			@echo "\033[1;92m\nmake bonus completed\n\033[0m"

.PHONY:		all clean fclean re bonus
