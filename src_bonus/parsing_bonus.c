/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:38 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/25 16:54:20 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

static void	check_nb_arguments(t_game *game, int fd, char **tab, char *tmp)
{
	if (tab[1] == NULL || ft_strstr(tab[1], "\n"))
		ft_free_vars_and_exit(game, tab, tmp, fd);
	if (tab[2] != NULL)
	{
		if (!ft_strstr(tab[2], "\n"))
			ft_free_vars_and_exit(game, tab, tmp, fd);
	}
}

static void	check_tmp(t_game *game, int fd, char **tab, char *tmp)
{
	if (!tmp)
		ft_free_vars_and_exit(game, tab, tmp, fd);
	else
	{
		free(tmp);
		tmp = NULL;
	}
}

static int	get_texture_and_color(t_game *game, int fd)
{
	int		index;
	int		count;
	char	*tmp;
	char	**tab;

	tmp = NULL;
	tab = NULL;
	index = 0;
	count = 0;
	while (index < 6)
	{
		tmp = get_next_line(fd);
		if (!(ft_strstr(tmp, "\n")) && tmp)
		{
			tab = ft_split(tmp, ' ');
			check_nb_arguments(game, fd, tab, tmp);
			if (get_path_and_color_name(game, tab))
				index++;
			free_tab(tab);
			tab = NULL;
		}
		check_tmp(game, fd, tab, tmp);
		count++;
	}
	return (count);
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
	int		count;

	fd = open(game->scene_name, O_RDONLY);
	count = get_texture_and_color(game, fd);
	get_map(game, count, fd);
}
