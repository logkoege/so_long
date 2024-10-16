/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_fonctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:04:13 by logkoege          #+#    #+#             */
/*   Updated: 2024/10/11 21:56:55 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_log *log)
{
	int	img_h;
	int	img_w;

	img_h = IMG_HEIGHT;
	img_w = IMG_WIDTH;
	log->player_up = mlx_xpm_file_to_image(log->mlx_ptr, IMG_PLAYER_UP,
			&img_w, &img_h);
	log->player_down = mlx_xpm_file_to_image(log->mlx_ptr, IMG_PLAYER_DOWN,
			&img_w, &img_h);
	log->player_right = mlx_xpm_file_to_image(log->mlx_ptr, IMG_PLAYER_RIGHT,
			&img_w, &img_h);
	log->player_left = mlx_xpm_file_to_image(log->mlx_ptr, IMG_PLAYER_LEFT,
			&img_w, &img_h);
	log->bed = mlx_xpm_file_to_image(log->mlx_ptr, IMG_BED,
			&img_w, &img_h);
	log->grass = mlx_xpm_file_to_image(log->mlx_ptr, IMG_GRASS,
			&img_w, &img_h);
	log->tree = mlx_xpm_file_to_image(log->mlx_ptr, IMG_TREE,
			&img_w, &img_h);
	log->master_ball = mlx_xpm_file_to_image(log->mlx_ptr, IMG_MASTER_BALL,
			&img_w, &img_h);
}

void	init_mlx(t_log *log)
{
	log->mlx_ptr = mlx_init();
	if (!log->mlx_ptr)
		ft_freexit(log, "error: mlx init\n");
	log->win_ptr = mlx_new_window(log->mlx_ptr, (log->map_x - 1) * IMG_WIDTH,
			IMG_HEIGHT * (log->nbligne), "so_long");
	if (!log->win_ptr)
		ft_freexit(log, "error: window init\n");
	load_img(log);
	render_game(log);
}

void	destroy_mlx(t_log *log)
{
	if (log->mlx_ptr)
	{
		if (log->player_up)
			mlx_destroy_image(log->mlx_ptr, log->player_up);
		if (log->player_down)
			mlx_destroy_image(log->mlx_ptr, log->player_down);
		if (log->player_right)
			mlx_destroy_image(log->mlx_ptr, log->player_right);
		if (log->player_left)
			mlx_destroy_image(log->mlx_ptr, log->player_left);
		if (log->bed)
			mlx_destroy_image(log->mlx_ptr, log->bed);
		if (log->grass)
			mlx_destroy_image(log->mlx_ptr, log->grass);
		if (log->tree)
			mlx_destroy_image(log->mlx_ptr, log->tree);
		if (log->master_ball)
			mlx_destroy_image(log->mlx_ptr, log->master_ball);
	}
	if (log->mlx_ptr)
		mlx_destroy_window(log->mlx_ptr, log->win_ptr);
}
