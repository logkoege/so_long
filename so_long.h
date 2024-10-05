/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 05:42:52 by logkoege          #+#    #+#             */
/*   Updated: 2024/10/05 18:17:22 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"
# include <string.h>

# define IMG_HEIGHT	50
# define IMG_WIDTH	40
# define TILE_SIZE	50

# define WALL		'1'
# define FLOOR 		'0'
# define COINS		'C'
# define PLAYER		'P'
# define MAP_EXIT	'E'

# define ESC		65307
# define W			119
# define A			97
# define S			115
# define D			100

# define IMG_TREE			"img_xpm/TREE.xpm"
# define IMG_MASTER_BALL	"img_xpm/MASTER_BALL.xpm"
# define IMG_GRASS			"img_xpm/GRASS.xpm"
# define IMG_BED			"img_xpm/BED.xpm"
# define IMG_PLAYER_UP		"img_xpm/PLAYER_UP.xpm"
# define IMG_PLAYER_DOWN	"img_xpm/PLAYER_DOWN.xpm"
# define IMG_PLAYER_LEFT	"img_xpm/PLAYER_LEFT.xpm"
# define IMG_PLAYER_RIGHT	"img_xpm/PLAYER_RIGHT.xpm"

typedef struct s_logan
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*map;
	int		player_x;
	int		player_y;
	int		map_x;
	int		map_y;
	int		player;
	int		len;
	int		nbligne;
	char	**tmap;
	int		i;
	int		j;
	int		c;
	int		p;
	int		e;
	int		check_c;
	int		check_p;
	int		check_e;
	char	**copy_map;
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	void	*bed;
	void	*tree;
	void	*grass;
	void	*master_ball;
	void	*img;
}	t_log;

//flood_parsing
void	ft_mapcmp(t_log *log);
void	copy_map(t_log *log);
void	find_player_xy(t_log *log);
void	flood_fill(t_log *log, int player_x, int player_y);

//img_fonctions
void	init_mlx(t_log *log);
void	load_img(t_log *log);
void	destroy_mlx(t_log *log);

//so_long_utils
void	tourmap(char *ligne, t_log *log);
void	ft_while_gnl(t_log *log, int fd, char *argv);
void	ft_size_ligne(int fd, t_log *log);
void	ft_check_cpe(t_log *log);
void	ft_parsmap(char *argv, t_log *log);

//ft_key_and_free
void	ft_freexit(t_log *log);
int		ft_close(t_log *log);
int		ft_key(int keycode, t_log *log);

#endif
