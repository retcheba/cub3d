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

void	ft_init_mini_map(t_game *game, t_img_data *mini_map)
{
	mini_map->img = mlx_new_image(game->mlx, 151, 151);
	mini_map->addr = mlx_get_data_addr(mini_map->img, &mini_map->bpp, \
		&mini_map->line_length, &mini_map->endian);
	ft_draw_grid(mini_map, game->grid_size, 150 / game->grid_size);
	my_mlx_pixel_put(mini_map, game->x, game->y, 0x00FFFF);
	my_mlx_pixel_put(mini_map, game->x + 1, game->y + 1, 0x00FFFF);
	my_mlx_pixel_put(mini_map, game->x, game->y + 1, 0x00FFFF);
	my_mlx_pixel_put(mini_map, game->x + 1, game->y, 0x00FFFF);
}

void	ft_draw_grid(t_img_data *mini_map, int grid_size, int cell_size)
{
	int	i;
	int	x;
	int	y;
	int	start_x;
	int	start_y;

	y = 0;
	while (y < grid_size + 1)
	{
		x = 0;
		while (x < grid_size + 1)
		{
			start_x = x * cell_size;
			start_y = y * cell_size;
			i = start_x - 1;
			while (i++ < start_x + cell_size)
				my_mlx_pixel_put(mini_map, i, start_y, 0xFFFFFF);
			i = start_y - 1;
			while (i++ < start_y + cell_size)
				my_mlx_pixel_put(mini_map, start_x, i, 0xFFFFFF);
			x++;
		}
		y++;
	}
}
