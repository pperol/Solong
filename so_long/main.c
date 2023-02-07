/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:45:56 by pperol            #+#    #+#             */
/*   Updated: 2022/06/16 14:17:31 by pperol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_letters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'C' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != '1'
				&& map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_read_map(char **argv)
{
	char	*buf;
	int		fdin;
	int		file;

	if (open(argv[1], O_DIRECTORY) != -1)
		ft_error(5);
	fdin = open(argv[1], O_RDONLY);
	if (fdin < 0)
		ft_error(0);
	file = 2147482;
	buf = ft_calloc(sizeof(char), 2147483);
	if (buf == NULL)
		ft_error(0);
	while (file != 0)
	{
		buf[file] = '\0';
		file = read(fdin, buf, 2147483);
	}
	if (ft_check_rectangle(buf) == 1)
		ft_error(6);
	if (ft_check_buf(buf) == 1)
		return (0);
	return (buf);
}

int	ft_check_map(char **map)
{
	int		i;
	size_t	j;

	i = 0;
	if (ft_check_letters(map) == 0)
		ft_cancel_game(map);
	while (map[i])
	{
		j = ft_strlen(map[i]);
		if ((i != 0) && (j != ft_strlen(map[i - 1])))
			ft_cancel_game(map);
		if (ft_strrchr(map[0], '0') != 0 || ft_strrchr(map[0], 'C') != 0
			|| ft_strrchr(map[0], 'E') != 0 || ft_strrchr(map[0], 'P') != 0)
			ft_cancel_game(map);
		if (map[i][0] != '1' || map[i][j - 1] != '1')
			ft_cancel_game(map);
		i++;
	}
	if (ft_strrchr(map[i - 1], '0') != 0 || ft_strrchr(map[i - 1], 'C') != 0
		|| ft_strrchr(map[i - 1], 'E') != 0 || ft_strrchr(map[i - 1], 'P') != 0)
		ft_cancel_game(map);
	return (1);
}

int	check_and_initialize_map(t_data *game, char *buf)
{
	int		y;
	int		x;

	game->steps = 1;
	game->map = ft_split(buf, '\n');
	free(buf);
	if (ft_check_map(game->map) != 1)
		ft_cancel_game(game->map);
	y = 0;
	while (game->map[y])
		y++;
	x = ft_strlen(game->map[0]);
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_cancel_game(game->map);
	game->win = mlx_new_window(game->mlx, x * 64, y * 64, "So long Bob!");
	if (game->win == NULL)
		ft_cancel_game(game->map);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*buf;
	t_data	game;

	if (argc != 2)
		ft_error(3);
	if (argv[1][0] == '.')
		ft_error(1);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == 0)
		ft_error(1);
	buf = ft_read_map(argv);
	ft_init_game(&game);
	if (buf == 0)
	{
		free(buf);
		ft_cancel_game(game.map);
	}
	if (check_and_initialize_map(&game, buf) == 0)
		return (0);
	ft_create_images(&game);
	ft_create_window(&game);
	mlx_key_hook(game.win, ft_bob_choice, &game);
	mlx_hook(game.win, 17, 0, ft_destroy_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
