/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 00:46:56 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/25 16:42:29 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	get_path_and_color_name(t_game *game, char **tab)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strstr(tab[0], "NO"))
		game->no_texture.path = remove_back_to_ligne(tab[1]);
	else if (ft_strstr(tab[0], "SO"))
		game->so_texture.path = remove_back_to_ligne(tab[1]);
	else if (ft_strstr(tab[0], "WE"))
		game->we_texture.path = remove_back_to_ligne(tab[1]);
	else if (ft_strstr(tab[0], "EA"))
		game->ea_texture.path = remove_back_to_ligne(tab[1]);
	else if (ft_strstr(tab[0], "F"))
		game->floor_color = ft_strdup(tab[1]);
	else if (ft_strstr(tab[0], "C"))
		game->ceiling_color = ft_strdup(tab[1]);
	else
		return (0);
	return (1);
}

int	ft_size_map(int fd)
{
	char	*tmp;
	int		size;

	size = 0;
	tmp = get_next_line(fd);
	if (tmp)
		size++;
	while (tmp)
	{
		if (tmp)
			free(tmp);
		tmp = get_next_line(fd);
		if (tmp)
			size++;
	}
	if (tmp)
		free(tmp);
	return (size + 2);
}

void	fill_map(t_game *game, int count, int fd)
{
	int		i;
	char	*tmp;

	fd = open(game->scene_name, O_RDONLY);
	while (count > 0)
	{
		tmp = get_next_line(fd);
		free(tmp);
		tmp = NULL;
		count--;
	}
	i = 0;
	tmp = get_next_line(fd);
	while (tmp)
	{
		game->map[i] = tmp;
		tmp = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
}
