/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subrandt <subrandt@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:28:28 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/14 17:59:41 by subrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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

void	check_path_and_color(t_game *game)
{
	printf("textures : \n%s%s%s%s%s%s\n", game->path_to_the_north_texture,
		game->path_to_the_east_texture, game->path_to_the_south_texture,
		game->path_to_the_west_texture, game->ceiling_color, game->floor_color);
		
	if (game->path_to_the_north_texture == NULL)
		ft_texture_errors(TX_FILE_ERROR, game);
	if (ft_strlen(game->path_to_the_north_texture) <= 4)
		ft_texture_errors(TX_FILE_ERROR, game);
	//if (ft_strncmp(game->path_to_the_north_texture
	//		+ ft_strlen(game->path_to_the_north_texture) - 4, ".xpm", 4) != 0)
	//	ft_texture_errors(TX_FILE_ERROR, game);
}