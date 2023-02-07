/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:42:24 by pperol            #+#    #+#             */
/*   Updated: 2022/06/09 13:38:40 by pperol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_images(t_data *game)
{
	int	img_width;
	int	img_height;

	game->sand = mlx_xpm_file_to_image(game->mlx, SAND_PATH, &img_width,
			&img_height);
	if (game->sand == NULL)
		ft_abort_game(game);
	game->rocks = mlx_xpm_file_to_image(game->mlx, ROCKS_PATH, &img_width,
			&img_height);
	if (game->rocks == NULL)
		ft_abort_game(game);
	game->bob = mlx_xpm_file_to_image(game->mlx, BOB_PATH, &img_width,
			&img_height);
	if (game->bob == NULL)
		ft_abort_game(game);
	game->krabby = mlx_xpm_file_to_image(game->mlx, KRABBY_PATH, &img_width,
			&img_height);
	if (game->krabby == NULL)
		ft_abort_game(game);
	game->home = mlx_xpm_file_to_image(game->mlx, HOME_PATH, &img_width,
			&img_height);
	if (game->home == NULL)
		ft_abort_game(game);
}

void	ft_add_image_to_window(t_data *game, int x, int y, char c)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->rocks, x, y);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->sand, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->krabby, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->bob, x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->home, x, y);
}

int	ft_create_window(t_data *game)
{
	int			i;
	size_t		j;
	int			x;
	int			y;

	i = 0;
	y = 0;
	while (game->map[i])
	{
		j = 0;
		x = 0;
		while (j < ft_strlen(game->map[0]))
		{
			ft_add_image_to_window(game, x, y, game->map[i][j]);
			x += 64;
			j++;
		}
		y += 64;
		i++;
	}
	return (0);
}
