/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:00:00 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/11 19:18:57 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_init_game(t_game *game)
{
	game->win_width = 1400;
	game->win_height = 865;
	game->path_to_the_north_texture = NULL;
	game->path_to_the_south_texture = NULL;
	game->path_to_the_west_texture = NULL;
	game->path_to_the_east_texture = NULL;
	game->floor_color = NULL;
	game->ceiling_color = NULL;
}

int	main(int argc, char **argv)
{
	t_game		game;

	ft_init_game(&game);
	check_scene_errors(argc, argv, &game);
	ft_parsing(&game);
	if (map_error_part2(&game))
		return (1);

	//A RECUP DANS MAP_ERROR_PART2
	game.len_x = 6;		//len x map
	game.len_y = 6;		//len y map
	game.x = 5;			//x du player
	game.y = 5;			//y du player
	game.pa = PI / 2;	//orientation (en Radian)
	
	game.pdx = cos(game.pa) * 3;
	game.pdy = sin(game.pa) * 3;
	game.pdx2 = cos(game.pa + (PI / 2)) * 3;
	game.pdy2 = sin(game.pa + (PI / 2)) * 3;
	if (game.len_x >= game.len_y)
		game.cell_size = 200 / game.len_x;
	else
		game.cell_size = 200 / game.len_y;
	game.px = (game.x * game.cell_size) - (game.cell_size / 2);
	game.py = (game.y * game.cell_size) - (game.cell_size / 2);

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.win_width, game.win_height, \
		"cub3d");
	ft_init_mini_map(&game, &game.mini_map);
	mlx_key_hook(game.win, ft_keypress, &game);
	mlx_hook(game.win, 17, 1, ft_close, &game);
	mlx_put_image_to_window(game.mlx, game.win, game.mini_map.img, 10, 10);
	mlx_loop(game.mlx);
	return (0);
}

int	ft_close(t_game *game)
{
	mlx_destroy_image(game->mlx, game->mini_map.img);
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
