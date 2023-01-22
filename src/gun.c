/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 01:44:00 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/22 04:24:00 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_init_gun_texture(t_game *game)
{
	game->gun.img = mlx_xpm_file_to_image(game->mlx, "textures/gun1.xpm", \
		&game->gun.img_width, &game->gun.img_height);
	if (!game->gun.img)
		ft_texture_and_color_errors(TX_FILE_ERROR, game);
	game->gun.addr = mlx_get_data_addr(game->gun.img, &game->gun.bpp, \
	&game->gun.line_length, &game->gun.endian);
}

void	ft_draw_gun(t_game *game, t_img_data *background_map)
{
	int	x;
	int	y;
	int	color;
	int	gun_width;
	int	gun_height;

	gun_width = 150;
	gun_height = 150;
	y = 0;
	while (y < gun_height)
	{
		x = -60;
		while (x < gun_width / 2)
		{
			color = get_color_texture(&game->gun, \
			get_coordinates_texture(x + 60, gun_width, game->gun.img_width), \
			get_coordinates_texture(y, gun_height, game->gun.img_height));
			if (color != 10701220)
				my_mlx_pixel_put(background_map, WIN_WIDTH / 2 + x, \
					WIN_HEIGHT - gun_height + y, color);
			x++;
		}
		y++;
	}
}

static void	ft_one_frame(t_game *game, char *gun_path, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		mlx_destroy_image(game->mlx, game->gun.img);
		mlx_destroy_image(game->mlx, game->mini_map.img);
		mlx_destroy_image(game->mlx, game->background_map.img);
		game->gun.img = mlx_xpm_file_to_image(game->mlx, gun_path, \
			&game->gun.img_width, &game->gun.img_height);
		game->gun.addr = mlx_get_data_addr(game->gun.img, &game->gun.bpp, \
			&game->gun.line_length, &game->gun.endian);
		ft_mini_map(game, &game->mini_map);
		ft_background_map(game, &game->background_map);
		mlx_put_image_to_window(game->mlx, game->win, game->background_map.img, \
			X_IMG, Y_IMG + 20 + 12 * game->len_y);
		mlx_put_image_to_window(game->mlx, game->win, game->mini_map.img, \
			10, 10);
		i++;
	}
}

void	ft_shot(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i == 0)
			ft_one_frame(game, "textures/gun1.xpm", 12);
		if (i == 1)
			ft_one_frame(game, "textures/gun2.xpm", 12);
		if (i == 2)
			ft_one_frame(game, "textures/gun3.xpm", 12);
		if (i == 3)
			ft_one_frame(game, "textures/gun4.xpm", 12);
		i++;
	}
	ft_one_frame(game, "textures/gun1.xpm", 1);
	ft_putstr_fd("PAN!\n", 2);
}
