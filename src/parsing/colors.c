/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subrandt <subrandt@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:05:42 by subrandt          #+#    #+#             */
/*   Updated: 2023/01/16 18:37:20 by subrandt         ###   ########.fr       */
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
	int		i;
	char 	**color;
	int		color_f;

	color_f = 0;
	color = ft_split(game->floor_color , ',');
	i = 0;
	while(color[i])
	{ 
		//printf("[%s]\n", color[i]);
		i++;
	}
	color_f += ft_atoi(color[0]) << 16;
	color_f += ft_atoi(color[1]) << 8;
	color_f += ft_atoi(color[2]);
	//printf("color_floor : %d\n", color_f);
	//printf("color_floor : %X\n", color_f);
	game->f_color = color_f;
	ft_free_colors(color);
}

static void	get_ceiling_color(t_game *game)
{
	int		i;
	char 	**color;
	int		color_c;

	color_c = 0;
	color = ft_split(game->ceiling_color , ',');
	i = 0;
	while(color[i])
	{
		//printf("[%s]\n", color[i]);
		i++;
	}
	color_c += ft_atoi(color[0]) << 16;
	color_c += ft_atoi(color[1]) << 8;
	color_c += ft_atoi(color[2]);
	//printf("color_ceiling : %d\n", color_c);
	//printf("color_ceiling : %X\n", color_c);
	game->f_color = color_c;
	ft_free_colors(color);
}

void	get_colors(t_game *game)
{
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
// check 2 virgules
// check atoi(color) 0-255
	get_floor_color(game);
	get_ceiling_color(game);
}
