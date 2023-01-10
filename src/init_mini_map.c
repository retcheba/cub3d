/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:46:49 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/10 14:35:34 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_draw_player(t_game *game, t_img_data *mini_map)
{
	my_mlx_pixel_put(mini_map, game->px, game->py, 0xFF0000);
	my_mlx_pixel_put(mini_map, game->px + 1, game->py + 1, 0xFF0000);
	my_mlx_pixel_put(mini_map, game->px, game->py + 1, 0xFF0000);
	my_mlx_pixel_put(mini_map, game->px + 1, game->py, 0xFF0000);
}

static void	ft_draw_one_square(t_game *game, int start_x, int start_y, \
	int color)
{
	int	i;
	int	j;

	i = start_y;
	while (i < start_y + game->cell_size)
	{
		j = start_x;
		while (j < start_x + game->cell_size)
		{
			my_mlx_pixel_put(&game->mini_map, i, j, color);
			j++;
		}
		i++;
	}
}

static void	ft_draw_squares(t_game *game, int cell_size)
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
				ft_draw_one_square(game, start_y, start_x, 0xFFFFFF);
			else if (game->map[y][x] == '0' || game->map[y][x] == 'N'
				|| game->map[y][x] == 'S' || game->map[y][x] == 'W'
				|| game->map[y][x] == 'E')
				ft_draw_one_square(game, start_y, start_x, 0x222222);
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
	mini_map->img = mlx_new_image(game->mlx, (game->len_x * game->cell_size), \
		(game->len_y * game->cell_size));
	mini_map->addr = mlx_get_data_addr(mini_map->img, &mini_map->bpp, \
		&mini_map->line_length, &mini_map->endian);
	ft_draw_squares(game, game->cell_size);
	ft_draw_grid(mini_map, game->len_y, game->len_x, game->cell_size);
	ft_draw_player(game, mini_map);
}
