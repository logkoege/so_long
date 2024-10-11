/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:48:27 by logkoege          #+#    #+#             */
/*   Updated: 2024/10/11 23:57:51 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_mv(int x, int y, t_log *log)
{
	char	new_place;

	if (new_place_valid(x, y, log))
	{
		new_place = log->tmap[log->player_y + y][log->player_x + x];
		if (new_place == 'E' && log->c > 0)
			return ;
		log->nb_of_mv++;
		ft_printf("count_move -> %d\n", log->nb_of_mv);
		log->tmap[log->player_y][log->player_x] = '0';
		log->player_y += y;
		log->player_x += x;
		if (new_place == 'C')
		{
			log->tmap[log->player_y][log->player_x] = '0';
			log->c--;
		}
		else if (new_place == 'E')
		{
			ft_freexit(log, "GG\n");
		}
		render_game(log);
	}
}

int	player_intructs(int keycode, t_log *log)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(log->mlx_ptr, log->win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (keycode == W)
	{
		log->player = 1;
		player_mv(0, -1, log);
	}
	if (keycode == A)
	{
		log->player = 2;
		player_mv(-1, 0, log);
	}
	if (keycode == S)
	{
		log->player = 0;
		player_mv(0, 1, log);
	}
	if (keycode == D)
	{
		log->player = 4;
		player_mv(1, 0, log);
	}
	return (0);
}
int	new_place_valid(int x, int y, t_log *log)
{
	char	new_place;
	
	new_place = log->tmap[log->player_y + y][log->player_x + x];
	if (new_place == '0' || new_place == 'C' ||new_place == 'E')
		return (1);
	return (0);
}
void	*img_place(char place, int player_direction, t_log *log)
{
	if (place == '1')
		return (log->tree);
	else if (place == '0')
		return (log->grass);
	else if (place == 'E')
		return (log->bed);
	else if (place == 'C')
		return (log->master_ball);
	else if (place == 'P')
	{
		if (player_direction == 1)
			return (log->player_up);
		if (player_direction == 2)
			return (log->player_left);
		if (player_direction == 0)
			return (log->player_down);
		if (player_direction == 4)
			return (log->player_right);
	}
	return (NULL);
}
void	render_game(t_log *log)
{
	int	x;
	int	y;
	
	y = 0;
	while(y < log->nbligne)
	{
		x = 0;
		while(x < log->map_x)
		{
			log->img = img_place(log->tmap[y][x], log->player, log);
			if (log->img)
			{
				mlx_put_image_to_window(log->mlx_ptr, log->win_ptr, log->img, x * IMG_WIDTH, y * IMG_HEIGHT);
			}
			x++;
		}
		y++;
	}
	log->img = img_place('P', log->player, log);
	mlx_put_image_to_window(log->mlx_ptr, log->win_ptr, log->img, log->player_x * IMG_WIDTH, log->player_y * IMG_HEIGHT);
}
