/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subrandt <subrandt@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:49:38 by subrandt          #+#    #+#             */
/*   Updated: 2023/01/17 09:11:31 by subrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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

void	check_color_errors(t_game *game)
{
	check_floor_color_commas(game);
	check_ceiling_color_commas(game);

	/*int i;

	i = 0;
	while (game->floor_color[i])
	{
		if (ft_isdigit(game->floor_color[i]) == 0 && game->floor_color[i])
			ft_texture_and_color_errors(COLOR_ERROR, game);
		else
			i++;

	}*/
// check digits 0-9 et ","
// check atoi(color) 0-255
}