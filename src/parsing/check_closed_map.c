/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subrandt <subrandt@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:27:24 by subrandt          #+#    #+#             */
/*   Updated: 2023/01/20 13:03:36 by subrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	check_surrounded(char **map, unsigned int i, unsigned int j, t_game *game)
{
	if (j == 0 || i == 0 || j >= ft_strlen(map[i]) - 2)
	{
		printf("i= %d, j=%d - erreur\n", i, j);
		ft_map_errors(MAP_ELEM_ERROR, game);
	}
	if (ft_strchr("0NWES1", map[i - 1][j]) == 0
		&& ft_strchr("0NWES1", map[i + 1][j]) == 0
		&& ft_strchr("0NWES1", map[i][j - 1]) == 0
		&& ft_strchr("0NWES1", map[i][j + 1]) == 0)
	{
		printf("i= %d, j=%d - erreur\n", i, j);
		ft_map_errors(MAP_ELEM_ERROR, game);
	}
	else
		printf("i= %d, j=%d - OK\n", i, j);
}

void	check_closed_map(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		//check_first_and_last_line(map[i], game);
		//check first 1 of column
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
			//else

		}
		printf("%s", map[i]);
		i++;
	}







	// while (map[i])
	// {
	// 	printf("i : %d\n", i);
	// 	printf("%s", map[i]);
	// 	if (i >= 1 && i <= ft_nb_lines(game) - 2)
	// 		check_other_lines(map[i], game);
	// 	else
	// 		check_first_and_last_line(map[i], game);
	// 	i++;
	// }
}
