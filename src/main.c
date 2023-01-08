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
	t_game	game;

	game.win_width = 1200;
	game.win_height = 740;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.win_width, game.win_height, \
		"cub3d");
	mlx_key_hook(game.win, ft_keypress, &game);
	mlx_hook(game.win, 17, 1, ft_close, &game);
	mlx_loop(game.mlx);
	return (0);
}

int	ft_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}
