/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_background_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:05:45 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/18 22:32:38 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_draw_background_color(t_game *game, t_img_data *background_map, \
	int img_width, int img_height)
{
	int	i;
	int	j;

	i = 0;
	while (i < img_height)
	{
		j = 0;
		while (j < img_width)
		{
			if (i < img_height / 2)
				my_mlx_pixel_put(background_map, j, i, game->c_color);
			else
				my_mlx_pixel_put(background_map, j, i, game->f_color);
			j++;
		}
		i++;
	}
}

static void	draw_wall_slice(t_img_data *background_map, int x, int y, int img_height, int color)
{
	if (y >= 0 && y < img_height)
       	my_mlx_pixel_put(background_map, x, y, color);
}

static void	ft_draw_walls(t_game *game, t_img_data *background_map, int img_height, int img_width)
{
	int	i;
	int	x;
	int	y;
	int	color;
	float	len;

	i = 0;
	x = 0;
	while (i < img_width)
	{
		len = game->lines_len[x][0];
		y = (img_height / 2) - (len / 2);
		while (y < ((img_height / 2) + (len / 2)))
		{
			if (game->lines_len[x][1] == NORTH)
				color = get_color_texture(&game->N_texture, get_x_texture(game, x), get_y_texture((y - (img_height / 2) + (len / 2)), len));
			else if (game->lines_len[x][1] == SOUTH)
				color = get_color_texture(&game->S_texture, get_x_texture(game, x), get_y_texture((y - (img_height / 2) + (len / 2)), len));
			else if (game->lines_len[x][1] == WEST)
				color = get_color_texture(&game->W_texture, get_x_texture(game, x), get_y_texture((y - (img_height / 2) + (len / 2)), len));
			else if (game->lines_len[x][1] == EAST)
				color = get_color_texture(&game->E_texture, get_x_texture(game, x), get_y_texture((y - (img_height / 2) + (len / 2)), len));
			else
				color = 0x000000;
			draw_wall_slice(background_map, img_width - i, y, img_height, color);
			y++;
		}
		i++;
		if (i % RAY_MULTI == 0)
			x++;
	}
}

void	ft_init_background_map(t_game *game, t_img_data	*background_map)
{
	int	img_width;
	int	img_height;

	img_width = IMG_WIDTH;
	img_height = IMG_HEIGHT;
	background_map->img = mlx_new_image(game->mlx, img_width, img_height);
	background_map->addr = mlx_get_data_addr(background_map->img, &background_map->bpp, \
		&background_map->line_length, &background_map->endian);
	ft_draw_background_color(game, background_map, img_width, img_height);
	ft_draw_walls(game, background_map, img_height, img_width);
}
