/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasring_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:53:03 by logkoege          #+#    #+#             */
/*   Updated: 2024/10/01 00:35:50 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_map(t_log *log)
{
	int	i;

	i = 0;
	log->copy_map = malloc(sizeof(char *) * (log->nbligne + 2));
	while (i < log->nbligne + 2)
	{
		log->copy_map[i] = ft_strdup(log->tmap[i]);
		i++;
	}
	find_player_xy(log);
	flood_fill(log, log->player_x, log->player_y);
	ft_mapcmp(log);
}

void	flood_fill(t_log *log, int player_x, int player_y)
{
	if (log->copy_map[player_y][player_x] == '1'
			|| log->copy_map[player_y][player_x] == 'V')
		return ;
	log->copy_map[log->player_y][log->player_x] = 'V';
	flood_fill(log, player_x + 1, player_y);
	flood_fill(log, player_x - 1, player_y);
	flood_fill(log, player_x, player_y + 1);
	flood_fill(log, player_x, player_y - 1);
}

void	find_player_xy(t_log *log)
{
	int	x;
	int	y;

	y = 0;
	while (log->tmap[y])
	{
		x = 0;
		while (log->tmap[y][x])
		{
			if (log->tmap[y][x] == 'P')
			{
				log->player_x = x;
				log->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	ft_mapcmp(t_log *log)
{
	int	i;
	int	j;

	j = 0;
	while (log->copy_map[j])
	{
		i = 0;
		while (log->copy_map[j][i])
		{
			if (log->copy_map[j][i] == 'C' || log->copy_map[j][i] == 'E')
			{
				ft_freexit(log);
			}
		}
	}
}
