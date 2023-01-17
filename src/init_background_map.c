/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_background_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:05:45 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/17 13:51:21 by retcheba         ###   ########.fr       */
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
	int	x;
	int	y;
	int	color;
	float	len;

	x = 0;
	while (x < img_width)
	{
		len = game->lines_len[x][0];
		//printf("line %d line_len %10f len %f\n", x, game->lines_len[x][0], len);
		y = (img_height / 2) - (len / 2);
		while (y < ((img_height / 2) + (len / 2)))
		{
			if (game->lines_len[x][1] == NORTH)
				color = YELLOW;
			else if (game->lines_len[x][1] == SOUTH)
				color = RED;
			else if (game->lines_len[x][1] == WEST)
				color = GREEN;
			else if (game->lines_len[x][1] == EAST)
				color = BLUE;
			else
				color = 0x000000;
//			color = WHITE;
			draw_wall_slice(background_map, img_width - x, y, img_height, color);
			y++;
		}
		x++;
	}
}

void	ft_init_background_map(t_game *game, t_img_data	*background_map)
{
	int	img_width;
	int	img_height;

	img_width = 600;
	img_height = 400;
	background_map->img = mlx_new_image(game->mlx, img_width, img_height);
	background_map->addr = mlx_get_data_addr(background_map->img, &background_map->bpp, \
		&background_map->line_length, &background_map->endian);
	ft_draw_background_color(game, background_map, img_width, img_height);
	ft_draw_walls(game, background_map, img_height, img_width);
}
