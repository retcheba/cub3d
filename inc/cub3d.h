/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:34:00 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/11 22:32:39 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "../libft/inc/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define ARG_ERROR			1
# define FILE_NAME_ERROR	2
# define FD_ERROR			3
# define CL_ERROR			4
# define MAP_RECT_ERROR		5
# define MAP_ELEM_ERROR		6
# define TX_FILE_ERROR		7
# define ESC 				65307
# define W 					119
# define S 					115
# define A 					97
# define D 					100
# define LEFT				65361
# define RIGHT				65363
# define PI					3.14159265359
# define SPEED				0.02
# define ROTATE_SPEED		0.00125

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
	t_img_data	mini_map;
}	t_game;

//	MAIN FUNCTIONS
int		ft_close(t_game *game);
int		ft_moves(t_game *game);
int		ft_keypress(int keycode, t_game *game);
int		ft_keyrelease(int keycode, t_game *game);
void	ft_init_mini_map(t_game *game, t_img_data *mini_map);
void	ft_draw_lines(t_game *game, t_img_data *mini_map);
//	PARSING
void	ft_parsing(t_game *game);
void	check_scene_errors(int argc, char **argv, t_game *game);
int		map_error_part2(t_game *game);
void	ft_scene_file_error(int nb_error);
void	ft_map_error(int nb_error, t_game *game);
void	ft_texture_errors(int nb_error, t_game *game);
//	TOOLS
void	my_mlx_pixel_put(t_img_data	*data, int x, int y, int color);
int		ft_strstr(char *str, char *to_find);
void	free_tab(char **tab);
void	ft_free_var_and_exit(t_game *game, char **tab, char *tmp);

#endif
