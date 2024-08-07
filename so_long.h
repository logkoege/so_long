/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 05:42:52 by logkoege          #+#    #+#             */
/*   Updated: 2024/08/05 16:01:15 by logkoege         ###   ########.fr       */
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

# define MAP_WIDTH 10
# define MAP_HEIGHT 10
# define TILE_SIZE 64

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

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
}	t_log;

void	tourmap(char *ligne, t_log *log);
void	ft_while(t_log *log, char *ligne, int fd);
void	ft_tligne(char *ligne, int fd, t_log *log);
void	ft_freexit(char *str);

#endif
