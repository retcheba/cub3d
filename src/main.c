/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:00:00 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/20 19:30:23 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_init_game(t_game *game)
{
	game->win_width = WIN_WIDTH;
	game->win_height = WIN_HEIGHT;
	game->path_to_the_north_texture = NULL;
	game->path_to_the_south_texture = NULL;
	game->path_to_the_west_texture = NULL;
	game->path_to_the_east_texture = NULL;
	game->floor_color = NULL;
	game->ceiling_color = NULL;
	game->W_DOWN = 0;
	game->S_DOWN = 0;
	game->A_DOWN = 0;
	game->D_DOWN = 0;
	game->LEFT_DOWN = 0;
	game->RIGHT_DOWN = 0;
	game->SPACE_DOWN = 0;
}

static void	ft_init_values(t_game *game)
{
	game->pdx = cosf(game->pa) * SPEED;
	game->pdy = sinf(game->pa) * SPEED;
	game->pdx2 = cosf(game->pa + (M_PI / 2.0)) * SPEED;
	game->pdy2 = sinf(game->pa + (M_PI / 2.0)) * SPEED;
	game->cell_size = 12;
	game->px = (game->x * game->cell_size) - (game->cell_size / 2);
	game->py = (game->y * game->cell_size) - (game->cell_size / 2);
}

static void	ft_init_textures(t_game *game)
{
	game->N_texture.img = mlx_xpm_file_to_image(game->mlx, "textures/N_wall.xpm", &game->texture_width, &game->texture_height);
	game->S_texture.img = mlx_xpm_file_to_image(game->mlx, "textures/S_wall.xpm", &game->texture_width, &game->texture_height);
	game->W_texture.img = mlx_xpm_file_to_image(game->mlx, "textures/W_wall.xpm", &game->texture_width, &game->texture_height);
	game->E_texture.img = mlx_xpm_file_to_image(game->mlx, "textures/E_wall.xpm", &game->texture_width, &game->texture_height);
	game->N_texture.addr = mlx_get_data_addr(game->N_texture.img, &game->N_texture.bpp, &game->N_texture.line_length, &game->N_texture.endian);
	game->S_texture.addr = mlx_get_data_addr(game->S_texture.img, &game->S_texture.bpp, &game->S_texture.line_length, &game->S_texture.endian);
	game->W_texture.addr = mlx_get_data_addr(game->W_texture.img, &game->W_texture.bpp, &game->W_texture.line_length, &game->W_texture.endian);
	game->E_texture.addr = mlx_get_data_addr(game->E_texture.img, &game->E_texture.bpp, &game->E_texture.line_length, &game->E_texture.endian);
	game->gun.img = mlx_xpm_file_to_image(game->mlx, "textures/gun1.xpm", &game->gun_width, &game->gun_height);
	game->gun.addr = mlx_get_data_addr(game->gun.img, &game->gun.bpp, &game->gun.line_length, &game->gun.endian);
}

int	main(int argc, char **argv)
{
	t_game		game;

	ft_init_game(&game);
	check_scene_errors(argc, argv, &game);
	ft_parsing(&game);
	if (map_error_part2(&game))
		return (1);
	ft_init_values(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.win_width, game.win_height + 20 + 12 * game.len_y, \
		"cub3d");
	ft_init_textures(&game);
	ft_init_mini_map(&game, &game.mini_map);
	ft_init_background_map(&game, &game.background_map);
	mlx_hook(game.win, 17, 1L<<0, ft_close, &game);
	mlx_hook(game.win, 2, 1L<<0, ft_keypress, &game);
	mlx_hook(game.win, 3, 1L<<1, ft_keyrelease, &game);
	mlx_loop_hook(game.mlx, ft_moves, &game);
	mlx_put_image_to_window(game.mlx, game.win, game.background_map.img, X_IMG, Y_IMG + 20 + 12 * game.len_y);
	mlx_put_image_to_window(game.mlx, game.win, game.mini_map.img, 10, 10);
	mlx_loop(game.mlx);
	return (0);
}

int	ft_close(t_game *game)
{
	mlx_destroy_image(game->mlx, game->gun.img);
	mlx_destroy_image(game->mlx, game->N_texture.img);
	mlx_destroy_image(game->mlx, game->S_texture.img);
	mlx_destroy_image(game->mlx, game->W_texture.img);
	mlx_destroy_image(game->mlx, game->E_texture.img);
	mlx_destroy_image(game->mlx, game->mini_map.img);
	mlx_destroy_image(game->mlx, game->background_map.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game->path_to_the_north_texture);
	free(game->path_to_the_south_texture);
	free(game->path_to_the_west_texture);
	free(game->path_to_the_east_texture);
	free(game->floor_color);
	free(game->ceiling_color);
	free_tab(game->map);
	exit(0);
	return (0);
}
