/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:38:51 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/25 16:31:09 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	*remove_back_to_ligne(char *str)
{
	char	**tab;
	char	*tmp;

	tab = ft_split(str, '\n');
	tmp = ft_strdup(tab[0]);
	free_tab(tab);
	return (tmp);
}

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

void	ft_free_vars_and_exit(t_game *game, char **tab, char *tmp, int fd)
{
	close(fd);
	if (tab)
		free_tab(tab);
	if (tmp)
		free(tmp);
	if (game->no_texture.path)
		free (game->no_texture.path);
	if (game->so_texture.path)
		free (game->so_texture.path);
	if (game->we_texture.path)
		free (game->we_texture.path);
	if (game->ea_texture.path)
		free (game->ea_texture.path);
	if (game->floor_color)
		free (game->floor_color);
	if (game->ceiling_color)
		free (game->ceiling_color);
	ft_putstr_fd("Error\nWrong scene\n", 2);
	exit(1);
}
