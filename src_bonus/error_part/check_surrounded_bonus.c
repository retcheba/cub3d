/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_surrounded.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subrandt <subrandt@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:27:55 by subrandt          #+#    #+#             */
/*   Updated: 2023/01/25 10:16:19 by subrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

void	check_surrounded(char **map, unsigned int i, unsigned int j,
	t_game *game)
{
	if (j == 0 || i == 0 || j >= ft_strlen(map[i]) - 2)
		ft_map_errors(MAP_ELEM_ERROR, game);
	if (j > (ft_strlen(game->map[i - 1]) - 1))
		ft_map_errors(MAP_ELEM_ERROR, game);
	if (j > (ft_strlen(game->map[i + 1]) - 1))
		ft_map_errors(MAP_ELEM_ERROR, game);
	if (ft_strchr("0NWES1", game->map[i - 1][j]) == NULL
		|| ft_strchr("0NWES1", game->map[i + 1][j]) == NULL
		|| ft_strchr("0NWES1", game->map[i][j - 1]) == NULL
		|| ft_strchr("0NWES1", game->map[i][j + 1]) == NULL)
		ft_map_errors(MAP_ELEM_ERROR, game);
	else
		return ;
}
