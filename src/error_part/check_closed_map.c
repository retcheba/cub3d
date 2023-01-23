/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subrandt <subrandt@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:27:24 by subrandt          #+#    #+#             */
/*   Updated: 2023/01/23 13:34:14 by subrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	check_first_line(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0')
			ft_map_errors(MAP_ELEM_ERROR, game);
		i++;
		if (line[i] == '\0' || line[i] == '\n')
			break ;
	}
}

static void	check_last_car_of_line(char *line, t_game *game)
{
	int	i;

	i = ft_strlen(line) - 1;
	while (line[i] && line[i] == ' ' && line[i] == '\n')
		i--;
	if (line[i - 1] != '1')
		ft_map_errors(MAP_ELEM_ERROR, game);
}

static void	check_first_car_of_line(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] != '1')
		ft_map_errors(MAP_ELEM_ERROR, game);
	check_last_car_of_line(line, game);
}

static void	check_last_line(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0')
			ft_map_errors(MAP_ELEM_ERROR, game);
		i++;
		if (line[i] == '\0' || line[i] == '\n')
			break ;
	}
}

void	check_closed_map(char **map, t_game *game)
{
	int	i;
	int	j;

	check_first_line(map[0], game);
	i = 1;
	while (map[i])
	{
		j = 0;
		check_first_car_of_line(map[i], game);
		while (map[i][j])
		{
			while (map[i][j] != '0' && map[i][j] != 'N' && map[i][j] != 'W'
				&& map[i][j] != 'E' && map[i][j] != 'S' && map[i][j])
				j++;
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'W'
				|| map[i][j] == 'E' || map[i][j] == 'S')
			{
				check_surrounded(map, i, j, game);
				j++;
			}
		}
		if (i == ft_nb_lines(game) - 1)
			check_last_line(map[ft_nb_lines(game) - 1], game);
		i++;
	}
}
