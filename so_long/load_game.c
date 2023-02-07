/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:51:12 by pperol            #+#    #+#             */
/*   Updated: 2022/06/16 10:57:18 by pperol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_collectable(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_exitable(int keycode, char **map, int i, int j)
{
	if (map[i][j + 1] == 'E' && keycode == 100
		&& is_collectable(map) == 0)
		return (1);
	else if (map[i][j - 1] == 'E' && keycode == 97
		&& is_collectable(map) == 0)
		return (1);
	else if (map[i - 1][j] == 'E' && keycode == 119
		&& is_collectable(map) == 0)
		return (1);
	else if (map[i + 1][j] == 'E' && keycode == 115
		&& is_collectable(map) == 0)
		return (1);
	return (0);
}

void	whereis_bob(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*y = j;
				*x = i;
			}
			j++;
		}
		i++;
	}
}

int	ft_move_bob(int keycode, t_data *game, int x, int y)
{
	int		i;
	int		j;
	char	c;

	whereis_bob(game->map, &i, &j);
	c = game->map[i][j];
	if (game->map[i + x][j + y] != '1' && game->map[i + x][j + y] != 'E')
		ft_printf("%d moves so far\n", game->steps++);
	if (is_exitable(keycode, game->map, i, j) == 1)
		ft_abort_game(game);
	else if (game->map[i + x][j + y] == 'C')
	{
		game->map[i + x][j + y] = c;
		game->map[i][j] = '0';
	}
	else if (game->map[i + x][j + y] == 'E'
		&& is_collectable(game->map) == 1)
		return (0);
	else if (game->map[i + x][j + y] == '0')
	{
		game->map[i + x][j + y] = c;
		game->map[i][j] = '0';
	}
	return (1);
}

int	ft_bob_choice(int keycode, t_data *game)
{
	if (keycode == 65307)
		ft_abort_game(game);
	if (keycode == 119)
		ft_move_bob(keycode, game, -1, 0);
	else if (keycode == 115)
		ft_move_bob(keycode, game, 1, 0);
	else if (keycode == 97)
		ft_move_bob(keycode, game, 0, -1);
	else if (keycode == 100)
		ft_move_bob(keycode, game, 0, 1);
	ft_create_window(game);
	return (0);
}
