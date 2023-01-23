/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:46:49 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/23 19:17:14 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

static void	ft_draw_player(t_game *game, t_img_data *mini_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			my_mlx_pixel_put(mini_map, game->player.px + (i - 1), \
				game->player.py + (j - 1), 0xFF0000);
			j++;
		}
		i++;
	}
}

static void	ft_draw_one_square(t_game *game, int start_x, int start_y, \
	int c)
{
	int	i;
	int	j;

	i = start_y;
	while (i < start_y + game->cell_size)
	{
		j = start_x;
		while (j < start_x + game->cell_size)
		{
			my_mlx_pixel_put(&game->mini_map, i, j, c);
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

void	ft_mini_map(t_game *game, t_img_data *mini_map)
{
	mini_map->img_width = game->len_x * game->cell_size;
	mini_map->img_height = game->len_y * game->cell_size;
	mini_map->img = mlx_new_image(game->mlx, mini_map->img_width, \
		mini_map->img_height);
	mini_map->addr = mlx_get_data_addr(mini_map->img, &mini_map->bpp, \
		&mini_map->line_length, &mini_map->endian);
	ft_draw_squares(game, game->cell_size);
	ft_draw_grid(mini_map, game->len_y, game->len_x, game->cell_size);
	ft_ray_caster(game);
	ft_draw_player(game, mini_map);
}
