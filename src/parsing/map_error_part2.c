/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_part2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subrandt <subrandt@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:39:51 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/11 16:53:16 by subrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
/*
static void	check_texture_format(t_game *game)
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

int	map_error_part2(t_game *game)//renommer
{
	(void)game;
	//check_textures(game);
	/*
	Vérifier:
	-	les paths pour les textures
	-	les couleurs
	
	-	la map (si y a que des caractères valides, bien fermé par des 1,
		1 seule position de départs) -> recupérer len_x et len_y (len de la map) 
		et récupérer aussi px et py (coordonnées du player)
	
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
