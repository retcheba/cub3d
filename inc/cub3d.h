/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subrandt <subrandt@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:34:00 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/20 13:10:03 by subrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "../libft/inc/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

// ERROR
# define ARG_ERROR			1
# define FILE_NAME_ERROR	2
# define FD_ERROR			3
# define CL_ERROR			4
# define MAP_ELEM_ERROR		5
# define TX_FILE_ERROR		6
# define COLOR_ERROR		7
# define PLAYER_ERROR		8
// KEYS
# define ESC 				65307
# define W 					119
# define S 					115
# define A 					97
# define D 					100
# define LEFT				65361
# define RIGHT				65363
// SPEED
# define SPEED				0.25
# define ROTATE_SPEED		0.011
# define COLLISION			15.0
// OTHER
# define DR					0.0174533
# define NORTH				10
# define SOUTH				11
# define EAST				12
# define WEST				13
# define WHITE				0xFFFFFF
# define RED				0xFF0000
# define GREEN				0x00FF00
# define BLUE				0x0000FF
# define YELLOW				0xFFFF00
# define NB_RAYS			450
# define RAY_MULTI			2
# define IMG_WIDTH			NB_RAYS * RAY_MULTI
# define IMG_HEIGHT			IMG_WIDTH / 1.618
# define X_IMG				0
# define Y_IMG				0
# define WIN_WIDTH			IMG_WIDTH
# define WIN_HEIGHT			IMG_HEIGHT 
# define CUBE_HEIGHT		10000.0

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_game
{
	char		*scene_name;
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	int			W_DOWN;
	int			S_DOWN;
	int			A_DOWN;
	int			D_DOWN;
	int			LEFT_DOWN;
	int			RIGHT_DOWN;
	char		**map;
	char		*path_to_the_north_texture;
	char		*path_to_the_south_texture;
	char		*path_to_the_west_texture;
	char		*path_to_the_east_texture;
	int			texture_width;
	int			texture_height;
	char		*floor_color;
	char		*ceiling_color;
	int			f_color;
	int			c_color;
	int			x;
	int			y;
	float		px;
	float		py;
	float		pdx;
	float		pdy;
	float		pdx2;
	float		pdy2;
	float		pa;
	int			len_x;
	int			len_y;
	int			cell_size;
	float		lines_len[NB_RAYS][4];;
	t_img_data	mini_map;
	t_img_data	background_map;
	t_img_data	N_texture;
	t_img_data	S_texture;
	t_img_data	W_texture;
	t_img_data	E_texture;
}	t_game;

//	MAIN FUNCTIONS
int		ft_close(t_game *game);
int		ft_moves(t_game *game);
int		ft_keypress(int keycode, t_game *game);
int		ft_keyrelease(int keycode, t_game *game);
void	ft_init_mini_map(t_game *game, t_img_data *mini_map);
void	ft_draw_lines(t_game *game, t_img_data *mini_map);
void	ft_init_background_map(t_game *game, t_img_data	*background_map);
int		get_color_texture(t_img_data *data, int x, int y);
int		get_y_texture(int y, float len);
int		get_x_texture(t_game *game, int i);
//	PARSING
void	ft_parsing(t_game *game);
void	check_scene_errors(int argc, char **argv, t_game *game);
int		ft_nb_lines(t_game *game);
int		map_error_part2(t_game *game);
void	ft_scene_file_error(int nb_error);
void	ft_map_errors(int nb_error, t_game *game);
void	check_closed_map(char **map, t_game *game);
void	ft_texture_and_color_errors(int nb_error, t_game *game);
void	check_path_and_color(t_game *game);
void	get_textures(t_game *game);
void	check_color_errors(t_game *game);
void	get_colors(t_game *game);
void	get_floor_color(t_game *game);
void	get_ceiling_color(t_game *game);
//	TOOLS
void	my_mlx_pixel_put(t_img_data	*data, int x, int y, int color);
int		ft_strstr(char *str, char *to_find);
void	free_tab(char **tab);
void	ft_free_var_and_exit(t_game *game, char **tab, char *tmp);

#endif
