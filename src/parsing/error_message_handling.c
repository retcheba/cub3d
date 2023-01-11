/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_handling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subrandt <subrandt@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:31:18 by subrandt          #+#    #+#             */
/*   Updated: 2023/01/11 16:26:52 by subrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	ft_free_and_exit(t_game *game)
{
	if (game->path_to_the_north_texture)
		free (game->path_to_the_north_texture);
	if (game->path_to_the_south_texture)
		free (game->path_to_the_south_texture);
	if (game->path_to_the_west_texture)
		free (game->path_to_the_west_texture);
	if (game->path_to_the_east_texture)
		free (game->path_to_the_east_texture);
	if (game->floor_color)
		free (game->floor_color);
	if (game->ceiling_color)
		free (game->ceiling_color);
	if (game->map)
		free (game->map);

}

//FILE ERRORS
void	ft_scene_file_error(int nb_error)
{
	if (nb_error == ARG_ERROR)
	{
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);
		ft_putstr_fd("Enter the scene file name!\n", 2);
	}
	if (nb_error == FILE_NAME_ERROR)
		ft_putstr_fd("Error\nEnter a *.cub file!\n", 2);
	if (nb_error == FD_ERROR)
		ft_putstr_fd("Error\nWhile reading the file (fd = -1).\n", 2);
	if (nb_error == CL_ERROR)
		ft_putstr_fd("Error\nWhile closing the file.\n", 2);
	exit(1);
}

//TEXTURE ERRORS
void	ft_texture_errors(int nb_error, t_game *game)
{
	if (nb_error == TX_FILE_ERROR)
	{
		ft_putstr_fd("Error\nWrong or missing texture file.", 2);
		ft_free_and_exit(game);
		exit(1);
	}

}

//MAP ERRORS
//void	ft_map_error(int nb_error, t_game *game)
//{
//	if (nb_error == MAP_ELEM_ERROR)
//		ft_putstr_fd("Error\nMap elements are not correct.\n", 2);
//	//ft_free(game);
//	//exit(0);
//}
