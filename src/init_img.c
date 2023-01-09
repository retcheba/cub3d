/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:46:49 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/08 22:46:55 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_draw_player(t_game *game, t_img_data *mini_map)
{
	my_mlx_pixel_put(mini_map, game->x, game->y, 0x00FFFF);
	my_mlx_pixel_put(mini_map, game->x + 1, game->y + 1, 0x00FFFF);
	my_mlx_pixel_put(mini_map, game->x, game->y + 1, 0x00FFFF);
	my_mlx_pixel_put(mini_map, game->x + 1, game->y, 0x00FFFF);
}

static void	ft_draw_one_square(t_img_data *mini_map, int start_x, int start_y, \
	int cell_size)
{
	int	i;
	int	j;

	i = start_y;
	while (i < start_y + cell_size)
	{
		j = start_x;
		while (j < start_x + cell_size)
		{
			my_mlx_pixel_put(mini_map, i, j, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

static void	ft_draw_squares(t_game *game, t_img_data *mini_map, int cell_size)
{
	int	x;
	int	y;
	int	start_x;
	int	start_y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			start_x = x * cell_size;
			start_y = y * cell_size;
			if (game->map[y][x] == '1')
				ft_draw_one_square(mini_map, start_y, start_x, cell_size);
			x++;
		}
		y++;
	}
}

static void	ft_draw_grid(t_img_data *mini_map, int len_y, int len_x, \
	int cell_size)
{
	int	i;
	int	x;
	int	y;
	int	start_x;
	int	start_y;

	y = 0;
	while (y < len_y)
	{
		x = 0;
		while (x < len_x)
		{
			start_x = x * cell_size;
			start_y = y * cell_size;
			i = start_x - 1;
			while (i++ < start_x + cell_size)
				my_mlx_pixel_put(mini_map, i, start_y, 0x000000);
			i = start_y - 1;
			while (i++ < start_y + cell_size)
				my_mlx_pixel_put(mini_map, start_x, i, 0x000000);
			x++;
		}
		y++;
	}
}

void	ft_init_mini_map(t_game *game, t_img_data *mini_map)
{
	if (game->len_x >= game->len_y)
		game->cell_size = 150 / game->len_x;
	else
		game->cell_size = 150 / game->len_y;
	mini_map->img = mlx_new_image(game->mlx, (game->len_x * game->cell_size), \
		(game->len_y * game->cell_size));
	mini_map->addr = mlx_get_data_addr(mini_map->img, &mini_map->bpp, \
		&mini_map->line_length, &mini_map->endian);
	ft_draw_squares(game, &game->mini_map, game->cell_size);
	ft_draw_grid(mini_map, game->len_y, game->len_x, game->cell_size);
	ft_draw_player(game, mini_map);
}
