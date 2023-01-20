/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:46:54 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/20 22:05:47 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_up(t_game *game)
{
	float	x2;
	float	y2;

	x2 = game->px + game->pdx;
	y2 = game->py - game->pdy;
	if (game->map[(int)(y2 - game->pdy * COLLISION) / game->cell_size][(int)(x2 + game->pdx * COLLISION) / game->cell_size] == '1')
		return ;
	game->px = x2;
	game->py = y2;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	mlx_destroy_image(game->mlx, game->background_map.img);
	ft_init_mini_map(game, &game->mini_map);
	ft_init_background_map(game, &game->background_map);
	mlx_put_image_to_window(game->mlx, game->win, game->background_map.img, X_IMG, Y_IMG + 20 + 12 * game->len_y);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

void	ft_down(t_game *game)
{
	float	x2;
	float	y2;

	x2 = game->px - game->pdx;
	y2 = game->py + game->pdy;
	if (game->map[(int)(y2 + game->pdy * COLLISION) / game->cell_size][(int)(x2 - game->pdx * COLLISION) / game->cell_size] == '1')
		return ;
	game->px = x2;
	game->py = y2;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	mlx_destroy_image(game->mlx, game->background_map.img);
	ft_init_mini_map(game, &game->mini_map);
	ft_init_background_map(game, &game->background_map);
	mlx_put_image_to_window(game->mlx, game->win, game->background_map.img, X_IMG, Y_IMG + 20 + 12 * game->len_y);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

void	ft_left(t_game *game)
{
	float	x2;
	float	y2;

	x2 = game->px + game->pdx2;
	y2 = game->py - game->pdy2;
	if (game->map[(int)(y2 - game->pdy2 * COLLISION) / game->cell_size][(int)(x2 + game->pdx2 * COLLISION) / game->cell_size] == '1')
		return ;
	game->px = x2;
	game->py = y2;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	mlx_destroy_image(game->mlx, game->background_map.img);
	ft_init_mini_map(game, &game->mini_map);
	ft_init_background_map(game, &game->background_map);
	mlx_put_image_to_window(game->mlx, game->win, game->background_map.img, X_IMG, Y_IMG + 20 + 12 * game->len_y);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

void	ft_right(t_game *game)
{
	float	x2;
	float	y2;

	x2 = game->px - game->pdx2;
	y2 = game->py + game->pdy2;
	if (game->map[(int)(y2 + game->pdy2 * COLLISION) / game->cell_size][(int)(x2 - game->pdx2 * COLLISION) / game->cell_size] == '1')
		return ;
	game->px = x2;
	game->py = y2;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	mlx_destroy_image(game->mlx, game->background_map.img);
	ft_init_mini_map(game, &game->mini_map);
	ft_init_background_map(game, &game->background_map);
	mlx_put_image_to_window(game->mlx, game->win, game->background_map.img, X_IMG, Y_IMG + 20 + 12 * game->len_y);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

void	ft_rotate_left(t_game *game)
{
	game->pa = game->pa + ROTATE_SPEED;
	if (game->pa > (2.0 * M_PI))
		game->pa -= (2.0 * M_PI);
	game->pdx = cosf(game->pa) * SPEED;
	game->pdy = sinf(game->pa) * SPEED;
	game->pdx2 = cosf(game->pa + (M_PI / 2.0)) * SPEED;
	game->pdy2 = sinf(game->pa + (M_PI / 2.0)) * SPEED;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	mlx_destroy_image(game->mlx, game->background_map.img);
	ft_init_mini_map(game, &game->mini_map);
	ft_init_background_map(game, &game->background_map);
	mlx_put_image_to_window(game->mlx, game->win, game->background_map.img, X_IMG, Y_IMG + 20 + 12 * game->len_y);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

void	ft_rotate_right(t_game *game)
{
	game->pa = game->pa - ROTATE_SPEED;
	if (game->pa < 0)
		game->pa += (2.0 * M_PI);
	game->pdx = cosf(game->pa) * SPEED;
	game->pdy = sinf(game->pa) * SPEED;
	game->pdx2 = cosf(game->pa + (M_PI / 2.0)) * SPEED;
	game->pdy2 = sinf(game->pa + (M_PI / 2.0)) * SPEED;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	mlx_destroy_image(game->mlx, game->background_map.img);
	ft_init_mini_map(game, &game->mini_map);
	ft_init_background_map(game, &game->background_map);
	mlx_put_image_to_window(game->mlx, game->win, game->background_map.img, X_IMG, Y_IMG + 20 + 12 * game->len_y);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
}

void	ft_shot(t_game *game)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		mlx_destroy_image(game->mlx, game->gun.img);
		mlx_destroy_image(game->mlx, game->mini_map.img);
		mlx_destroy_image(game->mlx, game->background_map.img);
		game->gun.img = mlx_xpm_file_to_image(game->mlx, "textures/gun1.xpm", &game->gun_width, &game->gun_height);
		game->gun.addr = mlx_get_data_addr(game->gun.img, &game->gun.bpp, &game->gun.line_length, &game->gun.endian);
		ft_init_mini_map(game, &game->mini_map);
		ft_init_background_map(game, &game->background_map);
		mlx_put_image_to_window(game->mlx, game->win, game->background_map.img, X_IMG, Y_IMG + 20 + 12 * game->len_y);
		mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
		i++;
	}
	i = 0;
	while (i < 12)
	{
		mlx_destroy_image(game->mlx, game->gun.img);
		mlx_destroy_image(game->mlx, game->mini_map.img);
		mlx_destroy_image(game->mlx, game->background_map.img);
		game->gun.img = mlx_xpm_file_to_image(game->mlx, "textures/gun2.xpm", &game->gun_width, &game->gun_height);
		game->gun.addr = mlx_get_data_addr(game->gun.img, &game->gun.bpp, &game->gun.line_length, &game->gun.endian);
		ft_init_mini_map(game, &game->mini_map);
		ft_init_background_map(game, &game->background_map);
		mlx_put_image_to_window(game->mlx, game->win, game->background_map.img, X_IMG, Y_IMG + 20 + 12 * game->len_y);
		mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
		i++;
	}
	i = 0;
	while (i < 12)
	{
		mlx_destroy_image(game->mlx, game->gun.img);
		mlx_destroy_image(game->mlx, game->mini_map.img);
		mlx_destroy_image(game->mlx, game->background_map.img);
		game->gun.img = mlx_xpm_file_to_image(game->mlx, "textures/gun3.xpm", &game->gun_width, &game->gun_height);
		game->gun.addr = mlx_get_data_addr(game->gun.img, &game->gun.bpp, &game->gun.line_length, &game->gun.endian);
		ft_init_mini_map(game, &game->mini_map);
		ft_init_background_map(game, &game->background_map);
		mlx_put_image_to_window(game->mlx, game->win, game->background_map.img, X_IMG, Y_IMG + 20 + 12 * game->len_y);
		mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
		i++;
	}
	i = 0;
	while (i < 12)
	{
		mlx_destroy_image(game->mlx, game->gun.img);
		mlx_destroy_image(game->mlx, game->mini_map.img);
		mlx_destroy_image(game->mlx, game->background_map.img);
		game->gun.img = mlx_xpm_file_to_image(game->mlx, "textures/gun4.xpm", &game->gun_width, &game->gun_height);
		game->gun.addr = mlx_get_data_addr(game->gun.img, &game->gun.bpp, &game->gun.line_length, &game->gun.endian);
		ft_init_mini_map(game, &game->mini_map);
		ft_init_background_map(game, &game->background_map);
		mlx_put_image_to_window(game->mlx, game->win, game->background_map.img, X_IMG, Y_IMG + 20 + 12 * game->len_y);
		mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
		i++;
	}
	mlx_destroy_image(game->mlx, game->gun.img);
	mlx_destroy_image(game->mlx, game->mini_map.img);
	mlx_destroy_image(game->mlx, game->background_map.img);
	game->gun.img = mlx_xpm_file_to_image(game->mlx, "textures/gun1.xpm", &game->gun_width, &game->gun_height);
	game->gun.addr = mlx_get_data_addr(game->gun.img, &game->gun.bpp, &game->gun.line_length, &game->gun.endian);
	ft_init_mini_map(game, &game->mini_map);
	ft_init_background_map(game, &game->background_map);
	mlx_put_image_to_window(game->mlx, game->win, game->background_map.img, X_IMG, Y_IMG + 20 + 12 * game->len_y);
	mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, 10, 10);
	ft_putstr_fd("PAN!\n", 2);
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
	if (game->SPACE_DOWN)
		ft_shot(game);
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
	if (keycode == SPACE)
		game->SPACE_DOWN = 1;
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
	if (keycode == SPACE)
		game->SPACE_DOWN = 0;
	return (0);
}
