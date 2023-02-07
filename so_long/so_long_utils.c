/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:27:10 by pperol            #+#    #+#             */
/*   Updated: 2022/06/16 11:16:03 by pperol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_game(t_data *game)
{
	game->bob = NULL;
	game->krabby = NULL;
	game->rocks = NULL;
	game->sand = NULL;
	game->home = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->steps = 0;
}

void	ft_free_tab(char **tab)
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

int	ft_cancel_game(char **map)
{
	if (map != NULL)
		ft_free_tab(map);
	ft_error(1);
	exit(0);
}

int	ft_abort_game(t_data *game)
{
	if (game->rocks)
		mlx_destroy_image(game->mlx, game->rocks);
	if (game->sand)
		mlx_destroy_image(game->mlx, game->sand);
	if (game->krabby)
		mlx_destroy_image(game->mlx, game->krabby);
	if (game->bob)
		mlx_destroy_image(game->mlx, game->bob);
	if (game->home)
		mlx_destroy_image(game->mlx, game->home);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_tab(game->map);
	exit(0);
}

int	ft_destroy_game(t_data *game)
{
	ft_abort_game(game);
	ft_error(4);
	exit(0);
}
