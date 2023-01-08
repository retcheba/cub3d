/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:00:00 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/06 16:04:08 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(void)
{
	t_game		game;
	t_img_data	mini_map;

	game.win_width = 1400;
	game.win_height = 865;
	game.mini_map = &mini_map;
	game.x = 75;
	game.y = 75;
	game.grid_size = 5;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.win_width, game.win_height, \
		"cub3d");
	ft_init_mini_map(&game, game.mini_map);
	mlx_key_hook(game.win, ft_keypress, &game);
	mlx_hook(game.win, 17, 1, ft_close, &game);
	mlx_put_image_to_window(game.mlx, game.win, game.mini_map->img, 10, 10);
	mlx_loop(game.mlx);
	return (0);
}

int	ft_close(t_game *game)
{
	mlx_destroy_image(game->mlx, game->mini_map->img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}
