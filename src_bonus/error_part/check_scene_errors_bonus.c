/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene_errors_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:28:28 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/23 19:18:36 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

//check file name "*.cub"
static void	check_scene_name(char *scene_file_name)
{
	if ((ft_strlen(scene_file_name) <= 4) || (ft_strncmp(scene_file_name
				+ ft_strlen(scene_file_name) - 4, ".cub", 4) != 0))
		ft_scene_file_error(FILE_NAME_ERROR);
}

//check open file
//check close file
static void	check_open_and_close_file(char *scene_file_name)
{
	int	fd;
	int	cl;

	fd = open(scene_file_name, O_RDONLY);
	if (fd == -1)
		ft_scene_file_error(FD_ERROR);
	cl = close(fd);
	if (cl != 0)
		ft_scene_file_error(CL_ERROR);
}

//check errors in scene file
void	check_scene_errors(int argc, char **argv, t_game *game)
{
	if (argc != 2)
		ft_scene_file_error(ARG_ERROR);
	check_scene_name(argv[1]);
	game->scene_name = argv[1];
	check_open_and_close_file(game->scene_name);
}
