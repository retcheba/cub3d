/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_handling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subrandt <subrandt@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:31:18 by subrandt          #+#    #+#             */
/*   Updated: 2023/01/10 12:03:51 by subrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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
	//exit(0);
}

//MAP ERRORS
//void	ft_map_error(int nb_error, t_game *game)
//{
//	if (nb_error == MAP_ELEM_ERROR)
//		ft_putstr_fd("Error\nMap elements are not correct.\n", 2);
//	//ft_free(game);
//	//exit(0);
//}