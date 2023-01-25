/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_handling_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:31:18 by subrandt          #+#    #+#             */
/*   Updated: 2023/01/23 19:18:52 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static void	ft_free_scene_and_map(t_game *game)
{
	if (game->gun.img)
		mlx_destroy_image(game->mlx, game->gun.img);
	if (game->no_texture.img)
		mlx_destroy_image(game->mlx, game->no_texture.img);
	if (game->so_texture.img)
		mlx_destroy_image(game->mlx, game->so_texture.img);
	if (game->we_texture.img)
		mlx_destroy_image(game->mlx, game->we_texture.img);
	if (game->ea_texture.img)
		mlx_destroy_image(game->mlx, game->ea_texture.img);
	if (game->mlx)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game->no_texture.path);
	free(game->so_texture.path);
	free(game->we_texture.path);
	free(game->ea_texture.path);
	free(game->floor_color);
	free(game->ceiling_color);
	free_tab(game->map);
}

//FILE ERRORS
void	ft_scene_file_error(int nb_error)
{
	if (nb_error == ARG_ERROR)
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);
	if (nb_error == FILE_NAME_ERROR)
		ft_putstr_fd("Error\nEnter a *.cub file!\n", 2);
	if (nb_error == FD_ERROR)
		ft_putstr_fd("Error\nWhile reading the file (fd = -1).\n", 2);
	if (nb_error == CL_ERROR)
		ft_putstr_fd("Error\nWhile closing the file.\n", 2);
	exit(1);
}

//TEXTURE AND COLOR ERRORS
void	ft_texture_and_color_errors(int nb_error, t_game *game)
{
	if (nb_error == TX_FILE_ERROR)
	{
		ft_putstr_fd("Error\nWrong or missing texture file.\n", 2);
		ft_free_scene_and_map(game);
		exit(1);
	}
	if (nb_error == COLOR_ERROR)
	{
		ft_putstr_fd("Error\nWrong color format.\n", 2);
		ft_free_scene_and_map(game);
		exit(1);
	}
}

//MAP ERRORS
void	ft_map_errors(int nb_error, t_game *game)
{
	(void)game;
	if (nb_error == MAP_ELEM_ERROR)
		ft_putstr_fd("Error\nMap elements are not correct.\n", 2);
	if (nb_error == PLAYER_ERROR)
		ft_putstr_fd("Error\nThere are more or less then one player.\n", 2);
	ft_free_scene_and_map(game);
	exit(1);
}
