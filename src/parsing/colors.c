/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subrandt <subrandt@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:05:42 by subrandt          #+#    #+#             */
/*   Updated: 2023/01/17 09:24:08 by subrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	ft_free_colors(char **color)
{
	int		i;

	i = 0;
	while (color[i])
	{
		free(color[i]);
		i++;
	}
	free(color);
}

static void	get_floor_color(t_game *game)
{
	char 	**color;
	int		color_f;

	color_f = 0;
	color = ft_split(game->floor_color , ',');
	color_f += ft_atoi(color[0]) << 16;
	color_f += ft_atoi(color[1]) << 8;
	color_f += ft_atoi(color[2]);
	game->f_color = color_f;
	ft_free_colors(color);
}

static void	get_ceiling_color(t_game *game)
{
	char 	**color;
	int		color_c;

	color_c = 0;
	color = ft_split(game->ceiling_color , ',');
	color_c += ft_atoi(color[0]) << 16;
	color_c += ft_atoi(color[1]) << 8;
	color_c += ft_atoi(color[2]);
	game->c_color = color_c;
	ft_free_colors(color);
}

void	get_colors(t_game *game)
{
	check_color_errors(game);
	get_floor_color(game);
	get_ceiling_color(game);
}
