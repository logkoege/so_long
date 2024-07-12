/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 05:42:52 by logkoege          #+#    #+#             */
/*   Updated: 2024/07/12 18:58:03 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define MAP_WIDTH 10
# define MAP_HEIGHT 10
# define TILE_SIZE 64

typedef struct s_logan
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_log;

#endif
