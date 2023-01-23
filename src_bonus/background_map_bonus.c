/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_map_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:05:45 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/23 19:16:23 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

static void	ft_draw_background_color(t_game *game, t_img_data *background_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			if (i < WIN_HEIGHT / 2)
				my_mlx_pixel_put(background_map, j, i, game->c_color);
			else
				my_mlx_pixel_put(background_map, j, i, game->f_color);
			j++;
		}
		i++;
	}
}

static void	draw_wall_slice(t_img_data *background_map, int x, int y, int color)
{
	if (y >= 0 && y < WIN_HEIGHT)
		my_mlx_pixel_put(background_map, x, y, color);
}

static int	get_px_color(t_game *game, int x, int y, float len)
{
	int		color;

	if (game->data_rays[x][1] == NORTH)
		color = get_color_texture(&game->no_texture, \
			get_x_texture(game, x, game->no_texture.img_width), \
			get_y_texture((y - (WIN_HEIGHT / 2) + (len / 2)), len, \
				game->no_texture.img_height));
	else if (game->data_rays[x][1] == SOUTH)
		color = get_color_texture(&game->so_texture, \
			get_x_texture(game, x, game->so_texture.img_width), \
			get_y_texture((y - (WIN_HEIGHT / 2) + (len / 2)), len, \
				game->so_texture.img_height));
	else if (game->data_rays[x][1] == WEST)
		color = get_color_texture(&game->we_texture, \
			get_x_texture(game, x, game->we_texture.img_width), \
			get_y_texture((y - (WIN_HEIGHT / 2) + (len / 2)), len, \
				game->we_texture.img_height));
	else if (game->data_rays[x][1] == EAST)
		color = get_color_texture(&game->ea_texture, \
			get_x_texture(game, x, game->ea_texture.img_width), \
			get_y_texture((y - (WIN_HEIGHT / 2) + (len / 2)), len, \
				game->ea_texture.img_height));
	else
		color = 0x000000;
	return (color);
}

static void	ft_draw_walls(t_game *game, t_img_data *background_map)
{
	int		i;
	int		x;
	int		y;
	int		color;
	float	len;

	i = 0;
	x = 0;
	while (i < WIN_WIDTH)
	{
		len = game->data_rays[x][0];
		y = (WIN_HEIGHT / 2) - (len / 2);
		while (y < ((WIN_HEIGHT / 2) + (len / 2)))
		{
			color = get_px_color(game, x, y, len);
			draw_wall_slice(background_map, WIN_WIDTH - i, y, color);
			y++;
		}
		i++;
		if (i % 2 == 0)
			x++;
	}
}

void	ft_background_map(t_game *game, t_img_data	*background_map)
{
	background_map->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	background_map->addr = mlx_get_data_addr(background_map->img, \
		&background_map->bpp, &background_map->line_length, \
		&background_map->endian);
	ft_draw_background_color(game, background_map);
	ft_draw_walls(game, background_map);
	ft_draw_gun(game, background_map);
}
