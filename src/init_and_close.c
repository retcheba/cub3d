/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 23:40:26 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/22 02:45:48 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_init_game(t_game *game)
{
	game->mlx = NULL;
	game->no_texture.path = NULL;
	game->so_texture.path = NULL;
	game->we_texture.path = NULL;
	game->ea_texture.path = NULL;
	game->no_texture.img = NULL;
	game->so_texture.img = NULL;
	game->we_texture.img = NULL;
	game->ea_texture.img = NULL;
	game->gun.img = NULL;
	game->floor_color = NULL;
	game->ceiling_color = NULL;
	game->keydown.w = 0;
	game->keydown.s = 0;
	game->keydown.a = 0;
	game->keydown.d = 0;
	game->keydown.left = 0;
	game->keydown.right = 0;
	game->keydown.space = 0;
}

int	ft_close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->gun.img);
	mlx_destroy_image(game->mlx, game->no_texture.img);
	mlx_destroy_image(game->mlx, game->so_texture.img);
	mlx_destroy_image(game->mlx, game->we_texture.img);
	mlx_destroy_image(game->mlx, game->ea_texture.img);
	mlx_destroy_image(game->mlx, game->mini_map.img);
	mlx_destroy_image(game->mlx, game->background_map.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game->no_texture.path);
	free(game->so_texture.path);
	free(game->we_texture.path);
	free(game->ea_texture.path);
	free(game->floor_color);
	free(game->ceiling_color);
	free_tab(game->map);
	exit(0);
	return (0);
}

void	ft_init_vars(t_game *game)
{
	game->cell_size = 12;
	game->player.dx = cosf(game->player.angle) * SPEED;
	game->player.dy = sinf(game->player.angle) * SPEED;
	game->player.dx2 = cosf(game->player.angle + (M_PI / 2.0)) * SPEED;
	game->player.dy2 = sinf(game->player.angle + (M_PI / 2.0)) * SPEED;
	game->player.px = (game->player.x * game->cell_size) - \
		(game->cell_size / 2);
	game->player.py = (game->player.y * game->cell_size) - \
		(game->cell_size / 2);
}

static void	get_data_textures(t_game *game)
{
	game->no_texture.addr = mlx_get_data_addr(game->no_texture.img, \
		&game->no_texture.bpp, &game->no_texture.line_length, \
		&game->no_texture.endian);
	game->so_texture.addr = mlx_get_data_addr(game->so_texture.img, \
		&game->so_texture.bpp, &game->so_texture.line_length, \
		&game->so_texture.endian);
	game->we_texture.addr = mlx_get_data_addr(game->we_texture.img, \
		&game->we_texture.bpp, &game->we_texture.line_length, \
		&game->we_texture.endian);
	game->ea_texture.addr = mlx_get_data_addr(game->ea_texture.img, \
		&game->ea_texture.bpp, &game->ea_texture.line_length, \
		&game->ea_texture.endian);
}

void	ft_init_textures(t_game *game)
{
	game->no_texture.img = mlx_xpm_file_to_image(game->mlx, \
		game->no_texture.path, &game->no_texture.img_width, \
		&game->no_texture.img_height);
	game->so_texture.img = mlx_xpm_file_to_image(game->mlx, \
		game->so_texture.path, &game->so_texture.img_width, \
		&game->so_texture.img_height);
	game->we_texture.img = mlx_xpm_file_to_image(game->mlx, \
		game->we_texture.path, &game->we_texture.img_width, \
		&game->we_texture.img_height);
	game->ea_texture.img = mlx_xpm_file_to_image(game->mlx, \
		game->ea_texture.path, &game->ea_texture.img_width, \
		&game->ea_texture.img_height);
	if (!game->no_texture.img || !game->so_texture.img
		|| !game->we_texture.img || !game->ea_texture.img)
		ft_texture_and_color_errors(TX_FILE_ERROR, game);
	get_data_textures(game);
	ft_init_gun_texture(game);
}
