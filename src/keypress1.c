/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:46:54 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/22 04:11:22 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_rotate_left(t_game *game)
{
	game->player.angle = game->player.angle + ROTATE_SPEED;
	if (game->player.angle > (2.0 * M_PI))
		game->player.angle -= (2.0 * M_PI);
	game->player.dx = cosf(game->player.angle) * SPEED;
	game->player.dy = sinf(game->player.angle) * SPEED;
	game->player.dx2 = cosf(game->player.angle + (M_PI / 2.0)) * SPEED;
	game->player.dy2 = sinf(game->player.angle + (M_PI / 2.0)) * SPEED;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	mlx_destroy_image(game->mlx, game->background_map.img);
	ft_mini_map(game, &game->mini_map);
	ft_background_map(game, &game->background_map);
	mlx_put_image_to_window(game->mlx, game->win, game->background_map.img, \
		X_IMG, Y_IMG + 20 + 12 * game->len_y);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

static void	ft_rotate_right(t_game *game)
{
	game->player.angle = game->player.angle - ROTATE_SPEED;
	if (game->player.angle < 0)
		game->player.angle += (2.0 * M_PI);
	game->player.dx = cosf(game->player.angle) * SPEED;
	game->player.dy = sinf(game->player.angle) * SPEED;
	game->player.dx2 = cosf(game->player.angle + (M_PI / 2.0)) * SPEED;
	game->player.dy2 = sinf(game->player.angle + (M_PI / 2.0)) * SPEED;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	mlx_destroy_image(game->mlx, game->background_map.img);
	ft_mini_map(game, &game->mini_map);
	ft_background_map(game, &game->background_map);
	mlx_put_image_to_window(game->mlx, game->win, game->background_map.img, \
		X_IMG, Y_IMG + 20 + 12 * game->len_y);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

int	ft_moves(t_game *game)
{
	if (game->keydown.w)
		ft_up(game);
	if (game->keydown.s)
		ft_down(game);
	if (game->keydown.a)
		ft_left(game);
	if (game->keydown.d)
		ft_right(game);
	if (game->keydown.left)
		ft_rotate_left(game);
	if (game->keydown.right)
		ft_rotate_right(game);
	if (game->keydown.space)
		ft_shot(game);
	return (0);
}

int	ft_keypress(int keycode, t_game *game)
{
	if (keycode == W)
		game->keydown.w = 1;
	if (keycode == S)
		game->keydown.s = 1;
	if (keycode == A)
		game->keydown.a = 1;
	if (keycode == D)
		game->keydown.d = 1;
	if (keycode == LEFT)
		game->keydown.left = 1;
	if (keycode == RIGHT)
		game->keydown.right = 1;
	if (keycode == SPACE)
		game->keydown.space = 1;
	return (0);
}

int	ft_keyrelease(int keycode, t_game *game)
{
	if (keycode == ESC)
		ft_close_game(game);
	if (keycode == W)
		game->keydown.w = 0;
	if (keycode == S)
		game->keydown.s = 0;
	if (keycode == A)
		game->keydown.a = 0;
	if (keycode == D)
		game->keydown.d = 0;
	if (keycode == LEFT)
		game->keydown.left = 0;
	if (keycode == RIGHT)
		game->keydown.right = 0;
	if (keycode == SPACE)
		game->keydown.space = 0;
	return (0);
}
