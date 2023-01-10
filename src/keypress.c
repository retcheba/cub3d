/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:46:54 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/10 14:22:33 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_up(t_game *game)
{
	if (game->map[(game->py - 2) / game->cell_size][game->px / game->cell_size] == '1'
		|| (game->py - 2 < 0))
		return ;
	game->py -= 2;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	ft_init_mini_map(game, &game->mini_map);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

void	ft_down(t_game *game)
{
	if (game->map[(game->py + 2) / game->cell_size][game->px / game->cell_size] == '1'
		|| (game->py + 2 >= (game->len_y * game->cell_size)))
		return ;
	game->py += 2;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	ft_init_mini_map(game, &game->mini_map);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

void	ft_left(t_game *game)
{
	if (game->map[game->py / game->cell_size][(game->px - 2) / game->cell_size] == '1'
		|| (game->px - 2 < 0))
		return ;
	game->px -= 2;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	ft_init_mini_map(game, &game->mini_map);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

void	ft_right(t_game *game)
{
	if (game->map[game->py / game->cell_size][(game->px + 2) / game->cell_size] == '1'
		|| (game->px + 2 >= (game->len_x * game->cell_size)))
		return ;
	game->px += 2;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	ft_init_mini_map(game, &game->mini_map);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

int	ft_keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
		ft_close(game);
	if (keycode == W)
		ft_up(game);
	if (keycode == S)
		ft_down(game);
	if (keycode == A)
		ft_left(game);
	if (keycode == D)
		ft_right(game);
	return (0);
}
