/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:38:51 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/10 22:09:12 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_strstr(char *str, char *to_find)
{
	int	i;

	if (str == NULL || to_find == NULL)
		return (0);
	i = 0;
	while (str[i] && to_find[i] && str[i] == to_find[i])
		i++;
	if (str[i] == '\0' && to_find[i] == '\0')
		return (1);
	return (0);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_var_and_exit(t_game *game, char **tab, char *tmp)
{
	free_tab(tab);
	free(tmp);
	if (game->path_to_the_north_texture)
		free (game->path_to_the_north_texture);
	if (game->path_to_the_south_texture)
		free (game->path_to_the_south_texture);
	if (game->path_to_the_west_texture)
		free (game->path_to_the_west_texture);
	if (game->path_to_the_east_texture)
		free (game->path_to_the_east_texture);
	if (game->floor_color)
		free (game->floor_color);
	if (game->ceiling_color)
		free (game->ceiling_color);
	ft_putstr_fd("Error\nWrong map\n", 2);
	exit(1);
}
