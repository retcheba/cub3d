/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_part1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subrandt <subrandt@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:28:28 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/10 12:10:46 by subrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	check_scene_name(char *scene_file_name)
{
	if ((ft_strlen(scene_file_name) <= 4) || (ft_strncmp(scene_file_name
				+ ft_strlen(scene_file_name) - 4, ".cub", 4) != 0))
	{
		ft_scene_file_error(FILE_NAME_ERROR);
		return (1);
	}
	return (0);
}

int	map_error_part1(int argc, char **argv, t_game *game)
{
	if (argc != 2)
	{
		ft_scene_file_error(ARG_ERROR);
		return (1);
	}
	if (check_scene_name(argv[1]) == 1)
		return (1);
	game->scene_name = argv[1];
	return (0);
}
