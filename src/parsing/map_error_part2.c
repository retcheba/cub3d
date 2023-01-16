/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_part2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subrandt <subrandt@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:39:51 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/16 12:37:09 by subrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*static void	check_texture_format(t_game *game)
{
	//check format texture
	if ()
		ft_texture_errors(TX_FILE_ERROR, game);
	//check path

}

//checks if all the textures are in the scene file
static void check_textures(t_game *game)
{
	printf("%s\n%s\n%s\n%s\n", game->path_to_the_north_texture, game->path_to_the_east_texture
		, game->path_to_the_south_texture, game->path_to_the_west_texture);
	
	//si aucune texture dans la structure
	if (!game->path_to_the_north_texture || !game->path_to_the_east_texture
		|| !game->path_to_the_south_texture || !game->path_to_the_west_texture)
		ft_texture_errors(TX_FILE_ERROR, game);
	
	check_texture_format(game);
}
*/
static int	ft_nb_lines(t_game *game)
{
	int	nb_lines;

	nb_lines = 0;
	while (game->map[nb_lines])
		nb_lines++;
	if (nb_lines <= 1)
		ft_map_errors(MAP_ELEM_ERROR, game);
	return (nb_lines);
}

static void	get_map_size(t_game *game)
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
	game->len_x = len_longest_line;
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
	if (check_only_one_player(game) != 1)
		ft_map_errors(PLAYER_ERROR, game);
}

/*static void print_map(t_game *game) //fonction à supprimer
{
	int	i = 0;
	while (game->map[i])
	{
		printf("%s", game->map[i]);
		i++;
	}
}
*/

static void	get_player_angle(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'N')
		game->pa = M_PI / 2;
	if (game->map[i][j] == 'S')
		game->pa = (3 * M_PI) / 2;
	if (game->map[i][j] == 'W')
		game->pa = M_PI;
	if (game->map[i][j] == 'E')
		game->pa = 0;
}

static void	get_player_pos_and_angle(t_game *game)
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
				game->x = j + 1;
				game->y = i + 1;
				get_player_angle(game, i, j);
				return ;
			}
			else
				j++;
		}
		i++;
	}
}

int	map_error_part2(t_game *game)//renommer
{
	(void)game;
	/*
	Vérifier:
	-	les paths pour les textures
	-	les couleurs*/
	check_path_and_color(game);
	//check_textures(game);

	//print_map(game); //fonction à supprimer
	check_all_map_elements(game); // check caracteres " ", 1, 0, N, W, S, E
	get_map_size(game); //recuperer len_x et len_y
	get_player_pos_and_angle(game);
	/*
	-	la map (si y a que des caractères valides, bien fermé par des 1,
		1 seule position de départs) -> recupérer len_x et len_y (len de la map) 
		et récupérer aussi px et py (coordonnées du player)
	}

	if (pas bon)
	{
		free(game->path_to_the_north_texture);
		free(game->path_to_the_south_texture);
		free(game->path_to_the_west_texture);
		free(game->path_to_the_east_texture);
		free(game->floor_color);
		free(game->ceiling_color);
		free_tab(game->map);
		return (1);
	}*/
	return (0);
}
