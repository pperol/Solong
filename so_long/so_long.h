/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:56:42 by pperol            #+#    #+#             */
/*   Updated: 2022/06/16 11:30:03 by pperol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "minilibx/mlx.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

# define SAND_PATH "./sprites/sand.xpm"
# define ROCKS_PATH "./sprites/rocks.xpm"
# define BOB_PATH "./sprites/bob.xpm"
# define KRABBY_PATH "./sprites/krabby.xpm"
# define HOME_PATH "./sprites/home.xpm"

typedef struct s_data {
	void	*sand;
	void	*rocks;
	void	*bob;
	void	*krabby;
	void	*home;
	void	*mlx;
	void	*win;
	char	**map;
	int		steps;
}	t_data;

void	ft_free_tab(char **tab);
int		ft_cancel_game(char **map);
int		ft_abort_game(t_data *game);
int		ft_destroy_game(t_data *game);
void	ft_create_images(t_data *game);
void	ft_add_image_to_window(t_data *game, int x, int y, char c);
int		ft_create_window(t_data *game);
int		is_collectable(char **map);
int		is_exitable(int keycode, char **map, int i, int j);
void	whereis_bob(char **map, int *x, int *y);
int		ft_move_bob(int keycode, t_data *game, int x, int y);
int		ft_bob_choice(int keycode, t_data *game);
void	ft_init_game(t_data *game);
int		ft_error(int i);
int		ft_check_rectangle(char *buf);
int		ft_check_buf(char *buf);
int		ft_error(int i);
int		ft_check_rectangle(char *buf);
int		ft_check_buf(char *buf);

#endif
