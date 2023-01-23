/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_errors_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:49:38 by subrandt          #+#    #+#             */
/*   Updated: 2023/01/23 19:18:04 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

// check if only 2 commas in the floor color
static void	check_floor_color_commas(t_game *game)
{
	int	i;
	int	nb_commas;

	i = 0;
	nb_commas = 0;
	while (game->floor_color[i])
	{
		if (game->floor_color[i] == ',')
			nb_commas++;
		i++;
	}
	if (nb_commas != 2)
		ft_texture_and_color_errors(COLOR_ERROR, game);
}

// check if only 2 commas in the ceiling color
static void	check_ceiling_color_commas(t_game *game)
{
	int	i;
	int	nb_commas;

	i = 0;
	nb_commas = 0;
	while (game->ceiling_color[i])
	{
		if (game->ceiling_color[i] == ',')
			nb_commas++;
		i++;
	}
	if (nb_commas != 2)
		ft_texture_and_color_errors(COLOR_ERROR, game);
}

//check length minimum and maximum length of texture path
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
	if (game->ceiling_color == NULL || game->floor_color == NULL)
		ft_texture_and_color_errors(COLOR_ERROR, game);
	if (ft_strlen(game->ceiling_color) <= 5
		|| ft_strlen(game->floor_color) <= 5)
		ft_texture_and_color_errors(COLOR_ERROR, game);
	if (ft_strlen(game->ceiling_color) >= 13
		|| ft_strlen(game->floor_color) >= 13)
		ft_texture_and_color_errors(COLOR_ERROR, game);
	check_floor_color_commas(game);
	check_ceiling_color_commas(game);
	get_floor_color(game);
	get_ceiling_color(game);
}
