/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:28:28 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/22 00:17:30 by retcheba         ###   ########.fr       */
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
	if (game->no_texture.path == NULL
		|| game->ea_texture.path == NULL
		|| game->so_texture.path == NULL
		|| game->we_texture.path == NULL)
		ft_texture_and_color_errors(TX_FILE_ERROR, game);
	if (ft_strlen(game->no_texture.path) <= 5
		|| ft_strlen(game->ea_texture.path) <= 5
		|| ft_strlen(game->so_texture.path) <= 5
		|| ft_strlen(game->we_texture.path) <= 5)
		ft_texture_and_color_errors(TX_FILE_ERROR, game);
	/*if (ft_strncmp(game->path_to_the_north_texture
			+ ft_strlen(game->path_to_the_north_texture) - 5, ".xpm\n", 5) != 0)
		ft_texture_and_color_errors(TX_FILE_ERROR, game);*/
	//printf("colors : \n%s%s\n", game->ceiling_color, game->floor_color);
	//printf("len floor color %zu\n", ft_strlen(game->floor_color));
	//printf("len ceiling color %zu\n", ft_strlen(game->ceiling_color));
	if (game->ceiling_color == NULL || game->floor_color == NULL)
		ft_texture_and_color_errors(COLOR_ERROR, game);
	if (ft_strlen(game->ceiling_color) <= 5
		|| ft_strlen(game->floor_color) <= 5)
		ft_texture_and_color_errors(COLOR_ERROR, game);
	if (ft_strlen(game->ceiling_color) >= 13
		|| ft_strlen(game->floor_color) >= 13)
		ft_texture_and_color_errors(COLOR_ERROR, game);
	get_colors(game);
}
