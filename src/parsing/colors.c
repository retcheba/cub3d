/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subrandt <subrandt@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:05:42 by subrandt          #+#    #+#             */
/*   Updated: 2023/01/17 17:03:10 by subrandt         ###   ########.fr       */
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

// check digits 0-9
static void	check_digits(char **color, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (color[i])
	{
		j = 0;
		while (color[i][j])
		{
			if (ft_isdigit(color[i][j]) || color[i][j] == '\n')
				j++;
			else
			{
				printf("erreur digit\n");
				ft_free_colors(color);
				ft_texture_and_color_errors(COLOR_ERROR, game);
			}
		}
		i++;
	}
}

// check atoi(color) 0-255
void	check_atoi(char **color, t_game *game)
{
	if (ft_atoi(color[0]) < 0 || ft_atoi(color[0]) > 255
		|| ft_atoi(color[1]) < 0 || ft_atoi(color[1]) > 255
		|| ft_atoi(color[2]) < 0 || ft_atoi(color[2]) > 255)
	{
		printf("digit inf 0 ou sup 255\n");
		ft_free_colors(color);
		ft_texture_and_color_errors(COLOR_ERROR, game);
	}
}

void	get_floor_color(t_game *game)
{
	char	**color;
	int		color_f;

	color_f = 0;
	color = ft_split(game->floor_color, ',');
	check_digits(color, game);
	check_atoi(color, game);
	color_f += ft_atoi(color[0]) << 16;
	color_f += ft_atoi(color[1]) << 8;
	color_f += ft_atoi(color[2]);
	game->f_color = color_f;
	ft_free_colors(color);
}

void	get_ceiling_color(t_game *game)
{
	char	**color;
	int		color_c;

	color_c = 0;
	color = ft_split(game->ceiling_color, ',');
	check_digits(color, game);
	check_atoi(color, game);
	color_c += ft_atoi(color[0]) << 16;
	color_c += ft_atoi(color[1]) << 8;
	color_c += ft_atoi(color[2]);
	game->c_color = color_c;
	ft_free_colors(color);
}
