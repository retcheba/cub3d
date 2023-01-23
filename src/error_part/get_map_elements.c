/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subrandt <subrandt@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:12:10 by subrandt          #+#    #+#             */
/*   Updated: 2023/01/23 11:48:04 by subrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

//get map dimensions : len_x and len_y
void	get_map_size(t_game *game)
{
	int		i;
	size_t	len_longest_line;
	size_t	len_next_line;

	game->len_y = ft_nb_lines(game);
	i = 0;
	len_longest_line = (ft_strlen(game->map[i]) - 1);
	while (game->map[i + 1])
	{
		len_next_line = (ft_strlen(game->map[i + 1]) - 1);
		if (len_next_line >= len_longest_line)
			len_longest_line = len_next_line;
		i++;
	}
	if (len_longest_line <= 2)
		ft_map_errors(MAP_ELEM_ERROR, game);
	game->len_x = len_longest_line;
}

//get point of vue of the player
static void	get_player_angle(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'N')
		game->player.angle = M_PI / 2;
	if (game->map[i][j] == 'S')
		game->player.angle = (3 * M_PI) / 2;
	if (game->map[i][j] == 'W')
		game->player.angle = M_PI;
	if (game->map[i][j] == 'E')
		game->player.angle = 0;
}

//get start-position of the player
void	get_player_pos_and_angle(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'W'
				|| game->map[i][j] == 'E' || game->map[i][j] == 'S')
			{
				game->player.x = j + 1;
				game->player.y = i + 1;
				get_player_angle(game, i, j);
				return ;
			}
			else
				j++;
		}
		i++;
	}
}
