/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:46:54 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/11 19:20:15 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_up(t_game *game)
{
	int	x2;
	int	y2;

	x2 = game->px + game->pdx;
	y2 = game->py - game->pdy;
	if (game->map[y2 / game->cell_size][x2 / game->cell_size] == '1')
		return ;
	game->px = x2;
	game->py = y2;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	ft_init_mini_map(game, &game->mini_map);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

void	ft_down(t_game *game)
{
	int	x2;
	int	y2;

	x2 = game->px - game->pdx;
	y2 = game->py + game->pdy;
	if (game->map[y2 / game->cell_size][x2 / game->cell_size] == '1')
		return ;
	game->px = x2;
	game->py = y2;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	ft_init_mini_map(game, &game->mini_map);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

void	ft_left(t_game *game)
{
	int	x2;
	int	y2;

	x2 = game->px + game->pdx2;
	y2 = game->py - game->pdy2;
	if (game->map[y2 / game->cell_size][x2 / game->cell_size] == '1')
		return ;
	game->px = x2;
	game->py = y2;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	ft_init_mini_map(game, &game->mini_map);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

void	ft_right(t_game *game)
{
	int	x2;
	int	y2;

	x2 = game->px - game->pdx2;
	y2 = game->py + game->pdy2;
	if (game->map[y2 / game->cell_size][x2 / game->cell_size] == '1')
		return ;
	game->px = x2;
	game->py = y2;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	ft_init_mini_map(game, &game->mini_map);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

void	ft_rotate_left(t_game *game)
{
	game->pa += 0.1;
	if (game->pa > (2 * PI))
		game->pa -= (2 * PI);
	game->pdx = cos(game->pa) * 3;
	game->pdy = sin(game->pa) * 3;
	game->pdx2 = cos(game->pa + (PI / 2)) * 3;
	game->pdy2 = sin(game->pa + (PI / 2)) * 3;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	ft_init_mini_map(game, &game->mini_map);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

void	ft_rotate_right(t_game *game)
{
	game->pa -= 0.1;
	if (game->pa < 0)
		game->pa += (2 * PI);
	game->pdx = cos(game->pa) * 3;
	game->pdy = sin(game->pa) * 3;
	game->pdx2 = cos(game->pa + (PI / 2)) * 3;
	game->pdy2 = sin(game->pa + (PI / 2)) * 3;
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
	if (keycode == LEFT)
		ft_rotate_left(game);
	if (keycode == RIGHT)
		ft_rotate_right(game);
	return (0);
}
