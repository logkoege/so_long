/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:50:53 by logkoege          #+#    #+#             */
/*   Updated: 2024/10/05 17:44:22 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key(int keycode, t_log *log)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(log->mlx_ptr, log->win_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	ft_close(t_log *log)
{
	mlx_destroy_window(log->mlx_ptr, log->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_freexit(t_log *log)
{
	int	j;

	j = 0;
	write(1, "Error\n", 6);
	if (log->tmap)
	{
		while (log->tmap[j])
		{
			free(log->tmap[j]);
			j++;
		}
		free(log->tmap);
	}
	if (log->copy_map)
	{
		j = 0;
		while (log->copy_map[j])
		{
			free(log->copy_map[j]);
			j++;
		}
		free(log->copy_map);
	}
	exit(EXIT_SUCCESS);
}
