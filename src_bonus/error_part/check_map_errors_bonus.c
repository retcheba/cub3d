/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:39:51 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/23 19:18:28 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int	ft_nb_lines(t_game *game)
{
	int	nb_lines;

	nb_lines = 0;
	while (game->map[nb_lines])
		nb_lines++;
	if (nb_lines <= 2)
		ft_map_errors(MAP_ELEM_ERROR, game);
	return (nb_lines);
}

static unsigned int	check_only_one_player(t_game *game)
{
	unsigned int	nb_players;
	int				i;
	int				j;

	nb_players = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'W'
				|| game->map[i][j] == 'E' || game->map[i][j] == 'S')
				nb_players++;
			j++;
		}
		i++;
	}
	return (nb_players);
}

// check the map elements : only " ", 1, 0, N, W, S, E
static void	check_all_map_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == ' ' || game->map[i][j] == '1'
				|| game->map[i][j] == '0' || game->map[i][j] == 'N'
				|| game->map[i][j] == 'W' || game->map[i][j] == 'E'
				|| game->map[i][j] == 'S' || game->map[i][j] == '\n')
				j++;
			else
				ft_map_errors(MAP_ELEM_ERROR, game);
		}
		i++;
	}
	check_closed_map(game->map, game);
	if (check_only_one_player(game) != 1)
		ft_map_errors(PLAYER_ERROR, game);
}

int	check_map_errors(t_game *game)
{
	check_path_and_color(game);
	check_all_map_elements(game);
	get_map_size(game);
	get_player_pos_and_angle(game);
	return (0);
}
