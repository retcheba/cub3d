/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:34:00 by retcheba          #+#    #+#             */
/*   Updated: 2023/02/01 14:59:22 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "mlx.h"
# include "../libft/inc/libft.h"
# include <fcntl.h>
# include <math.h>

// ERROR_CODES
# define ARG_ERROR			1
# define FILE_NAME_ERROR	2
# define FD_ERROR			3
# define CL_ERROR			4
# define MAP_ELEM_ERROR		5
# define TX_FILE_ERROR		6
# define COLOR_ERROR		7
# define PLAYER_ERROR		8
// KEY_CODES
# define ESC 				65307
# define W 					119
# define S 					115
# define A 					97
# define D 					100
# define LEFT				65361
# define RIGHT				65363
# define SPACE				32
// FACES
# define NORTH				10
# define SOUTH				11
# define EAST				12
# define WEST				13
// SPEEDS
# define SPEED				0.275
# define ROTATE_SPEED		0.0135
// OTHERS
# define WIN_WIDTH			900
# define WIN_HEIGHT			560
# define NB_RAYS			450
# define CUBE_HEIGHT		10000.0
# define COLLISION			15.0
# define DR					0.0174533

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
	char	*path;
}	t_img_data;

typedef struct s_keydown
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
	int	space;
}	t_keydown;

typedef struct s_player
{
	int			x;
	int			y;
	float		px;
	float		py;
	float		dx;
	float		dy;
	float		dx2;
	float		dy2;
	float		angle;
}	t_player;

typedef struct s_raycast
{
	float	x;
	float	y;
	float	ox;
	float	oy;
	float	dx;
	float	dy;
	float	err;
}	t_raycast;

typedef struct s_game
{
	char		*scene_name;
	void		*mlx;
	void		*win;
	char		**map;
	char		*floor_color;
	char		*ceiling_color;
	int			f_color;
	int			c_color;
	int			len_x;
	int			len_y;
	int			cell_size;
	float		data_rays[NB_RAYS][4];
	t_player	player;
	t_raycast	raycast;
	t_keydown	keydown;
	t_img_data	mini_map;
	t_img_data	background_map;
	t_img_data	no_texture;
	t_img_data	so_texture;
	t_img_data	we_texture;
	t_img_data	ea_texture;
	t_img_data	gun;
}	t_game;

//	INIT AND CLOSE
void	ft_init_game(t_game *game);
void	ft_init_vars(t_game *game);
void	ft_init_textures(t_game *game);
int		ft_close_game(t_game *game);
//	PARSING
void	ft_parsing(t_game *game);
int		get_path_and_color_name(t_game *game, char **tab);
int		ft_size_map(int fd);
void	fill_map(t_game *game, int count, int fd);
//	KEYPRESS
int		ft_moves(t_game *game);
int		ft_keypress(int keycode, t_game *game);
int		ft_keyrelease(int keycode, t_game *game);
void	ft_up(t_game *game);
void	ft_down(t_game *game);
void	ft_left(t_game *game);
void	ft_right(t_game *game);
//	MAP
void	ft_mini_map(t_game *game, t_img_data *mini_map);
void	ft_background_map(t_game *game, t_img_data	*background_map);
void	ft_draw_mini_map(t_game *game, t_img_data *background_map);
//	RAY_CASTING
void	ft_ray_caster(t_game *game);
int		hit_a_wall(t_game *game, float x, float y);
void	ft_put_pixel(t_game *game, t_raycast *raycast);
void	incr_or_decr_xy(t_game *game, t_raycast *raycast, float x2, float y2);
//	GET_COLOR_TEXTURE
int		get_color_texture(t_img_data *data, int x, int y);
int		get_y_texture(int y1, float len1, int len2);
int		get_x_texture(t_game *game, int i, int len2);
int		get_coordinates_texture(int c1, int len1, int len2);
//	ERROR_PART
void	check_scene_errors(int argc, char **argv, t_game *game);
int		ft_nb_lines(t_game *game);
int		check_map_errors(t_game *game);
void	ft_scene_file_error(int nb_error);
void	ft_map_errors(int nb_error, t_game *game);
void	check_surrounded(char **map, unsigned int i, unsigned int j,
			t_game *game);
void	check_closed_map(char **map, t_game *game);
void	ft_texture_and_color_errors(int nb_error, t_game *game);
void	check_path_and_color(t_game *game);
void	get_floor_color(t_game *game);
void	get_ceiling_color(t_game *game);
void	get_map_size(t_game *game);
void	get_player_pos_and_angle(t_game *game);
void	ft_error_display(t_game *game);
//	TOOLS
char	*remove_back_to_ligne(char *str);
void	my_mlx_pixel_put(t_img_data	*data, int x, int y, int color);
int		ft_strstr(char *str, char *to_find);
void	free_tab(char **tab);
void	ft_free_vars_and_exit(t_game *game, char **tab, char *tmp, int fd);
//	GUN
void	ft_init_gun_texture(t_game *game);
void	ft_draw_gun(t_game *game, t_img_data *background_map);
void	ft_shot(t_game *game);

#endif
