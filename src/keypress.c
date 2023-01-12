/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:46:54 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/11 22:29:25 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_up(t_game *game)
{
	float	x2;
	float	y2;

	x2 = game->px + game->pdx;
	y2 = game->py - game->pdy;
	if (game->map[(int)y2 / game->cell_size][(int)x2 / game->cell_size] == '1')
		return ;
	game->px = x2;
	game->py = y2;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	ft_init_mini_map(game, &game->mini_map);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

void	ft_down(t_game *game)
{
	float	x2;
	float	y2;

	x2 = game->px - game->pdx;
	y2 = game->py + game->pdy;
	if (game->map[(int)y2 / game->cell_size][(int)x2 / game->cell_size] == '1')
		return ;
	game->px = x2;
	game->py = y2;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	ft_init_mini_map(game, &game->mini_map);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

void	ft_left(t_game *game)
{
	float	x2;
	float	y2;

	x2 = game->px + game->pdx2;
	y2 = game->py - game->pdy2;
	if (game->map[(int)y2 / game->cell_size][(int)x2 / game->cell_size] == '1')
		return ;
	game->px = x2;
	game->py = y2;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	ft_init_mini_map(game, &game->mini_map);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

void	ft_right(t_game *game)
{
	float	x2;
	float	y2;

	x2 = game->px - game->pdx2;
	y2 = game->py + game->pdy2;
	if (game->map[(int)y2 / game->cell_size][(int)x2 / game->cell_size] == '1')
		return ;
	game->px = x2;
	game->py = y2;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	ft_init_mini_map(game, &game->mini_map);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

void	ft_rotate_left(t_game *game)
{
	game->pa = game->pa + ROTATE_SPEED;
	if (game->pa > (2 * PI))
		game->pa -= (2 * PI);
	game->pdx = cos(game->pa) * SPEED;
	game->pdy = sin(game->pa) * SPEED;
	game->pdx2 = cos(game->pa + (PI / 2)) * SPEED;
	game->pdy2 = sin(game->pa + (PI / 2)) * SPEED;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	ft_init_mini_map(game, &game->mini_map);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

void	ft_rotate_right(t_game *game)
{
	game->pa = game->pa - ROTATE_SPEED;
	if (game->pa < 0)
		game->pa += (2 * PI);
	game->pdx = cos(game->pa) * SPEED;
	game->pdy = sin(game->pa) * SPEED;
	game->pdx2 = cos(game->pa + (PI / 2)) * SPEED;
	game->pdy2 = sin(game->pa + (PI / 2)) * SPEED;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	ft_init_mini_map(game, &game->mini_map);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

int	ft_moves(t_game *game)
{
	if (game->W_DOWN)
		ft_up(game);
	if (game->S_DOWN)
		ft_down(game);
	if (game->A_DOWN)
		ft_left(game);
	if (game->D_DOWN)
		ft_right(game);
	if (game->LEFT_DOWN)
		ft_rotate_left(game);
	if (game->RIGHT_DOWN)
		ft_rotate_right(game);
	return (0);
}

int	ft_keypress(int keycode, t_game *game)
{
	if (keycode == W)
		game->W_DOWN = 1;
	if (keycode == S)
		game->S_DOWN = 1;
	if (keycode == A)
		game->A_DOWN = 1;
	if (keycode == D)
		game->D_DOWN = 1;
	if (keycode == LEFT)
		game->LEFT_DOWN = 1;
	if (keycode == RIGHT)
		game->RIGHT_DOWN = 1;
	return (0);
}

int	ft_keyrelease(int keycode, t_game *game)
{
	if (keycode == ESC)
		ft_close(game);
	if (keycode == W)
		game->W_DOWN = 0;
	if (keycode == S)
		game->S_DOWN = 0;
	if (keycode == A)
		game->A_DOWN = 0;
	if (keycode == D)
		game->D_DOWN = 0;
	if (keycode == LEFT)
		game->LEFT_DOWN = 0;
	if (keycode == RIGHT)
		game->RIGHT_DOWN = 0;
	return (0);
}
