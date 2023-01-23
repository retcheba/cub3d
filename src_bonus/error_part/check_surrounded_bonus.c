/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_surrounded_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:27:55 by subrandt          #+#    #+#             */
/*   Updated: 2023/01/23 19:18:41 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

void	check_surrounded(char **map, unsigned int i, unsigned int j,
	t_game *game)
{
	if (j == 0 || i == 0 || j >= ft_strlen(map[i]) - 2)
		ft_map_errors(MAP_ELEM_ERROR, game);
	if (ft_strchr("0NWES1", map[i - 1][j]) == NULL
		|| ft_strchr("0NWES1", map[i + 1][j]) == NULL
		|| ft_strchr("0NWES1", map[i][j - 1]) == NULL
		|| ft_strchr("0NWES1", map[i][j + 1]) == NULL)
		ft_map_errors(MAP_ELEM_ERROR, game);
	else
		return ;
}
