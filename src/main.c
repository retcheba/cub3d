/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:00:00 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/28 19:15:27 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_game		game;

	ft_init_game(&game);
	check_scene_errors(argc, argv, &game);
	ft_parsing(&game);
	if (check_map_errors(&game))
		return (1);
	ft_init_vars(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		ft_error_display(&game);
	game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	ft_init_textures(&game);
	ft_mini_map(&game, &game.mini_map);
	ft_background_map(&game, &game.background_map);
	mlx_hook(game.win, 17, 1, ft_close_game, &game);
	mlx_hook(game.win, 2, 1, ft_keypress, &game);
	mlx_hook(game.win, 3, 2, ft_keyrelease, &game);
	mlx_loop_hook(game.mlx, ft_moves, &game);
	mlx_put_image_to_window(game.mlx, game.win, game.background_map.img, 0, 0);
	mlx_loop(game.mlx);
	return (0);
}
