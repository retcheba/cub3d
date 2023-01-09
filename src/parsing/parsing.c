/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:38 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/09 13:58:40 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	get_path_and_color_name(t_game *game, char **tab)
{
	if (ft_strstr(tab[0], "NO"))
		game->path_to_the_north_texture = ft_strdup(tab[1]);
	else if (ft_strstr(tab[0], "SO"))
		game->path_to_the_south_texture = ft_strdup(tab[1]);
	else if (ft_strstr(tab[0], "WE"))
		game->path_to_the_west_texture = ft_strdup(tab[1]);
	else if (ft_strstr(tab[0], "EA"))
		game->path_to_the_east_texture = ft_strdup(tab[1]);
	else if (ft_strstr(tab[0], "F"))
		game->floor_color = ft_strdup(tab[1]);
	else if (ft_strstr(tab[0], "C"))
		game->ceiling_color = ft_strdup(tab[1]);
	else
		return (0);
	return (1);
}

static int	ft_size_map(int fd)
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

static void	fill_map(t_game *game, int count, int fd)
{
	int		i;
	char	*tmp;

	fd = open(game->map_name, O_RDONLY);
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

static void	get_map(t_game *game, int count, int fd)
{
	char	*tmp;

	tmp = get_next_line(fd);
	while (ft_strstr(tmp, "\n"))
	{
		count++;
		free(tmp);
		tmp = NULL;
		tmp = get_next_line(fd);
	}
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	game->map = NULL;
	game->map = malloc(ft_size_map(fd) * sizeof(char *));
	if (!game->map)
		return ;
	close (fd);
	fill_map(game, count, fd);
}

void	ft_parsing(t_game *game)
{
	int		fd;
	int		index;
	int		count;
	char	*tmp;
	char	**tab;

	index = 0;
	count = 0;
	fd = open(game->map_name, O_RDONLY);
	while (index < 6)
	{
		tmp = get_next_line(fd);
		if (!(ft_strstr(tmp, "\n")))
		{
			tab = ft_split(tmp, ' ');
			if (tab[2] != NULL)
				ft_free_var_and_exit(game, tab, tmp);
			if (get_path_and_color_name(game, tab))
				index++;
			free_tab(tab);
		}
		free(tmp);
		count++;
	}
	get_map(game, count, fd);
}
