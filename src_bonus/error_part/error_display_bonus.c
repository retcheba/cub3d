/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_display_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:08:22 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/28 19:16:49 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

void	ft_error_display(t_game *game)
{
	ft_putstr_fd("Error\nDISPLAY has been unset\n", 2);
	free(game->mlx);
	free(game->no_texture.path);
	free(game->so_texture.path);
	free(game->we_texture.path);
	free(game->ea_texture.path);
	free(game->floor_color);
	free(game->ceiling_color);
	free_tab(game->map);
	exit(1);
}
