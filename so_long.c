/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:05:58 by logkoege          #+#    #+#             */
/*   Updated: 2024/07/24 16:26:33 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_parsmap(char *argv, t_log *log)
{
	int	fd;
	char	*ligne;
	
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(EXIT_SUCCESS);
	while(1)
	{
		ligne = get_next_line(fd);
		if (!ligne)
			break ;
		log->map_X = ft_strlen(ligne);
		log->map = ft_strjoin(log->map, ligne);
		free(ligne);
		log->map_Y++;
	}
	if (log->map_Y == log->map_X)
	{
		exit(EXIT_SUCCESS);
	}
	close(fd);
}
void	test_error(int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
		exit(EXIT_FAILURE);
	len = strlen(argv[1]);
	if (argv[1][len - 1] == 'r' && argv[1][len - 2] == 'e' && argv[1][len - 3] == 'b' && argv[1][len - 4] == '.')
		return ;
	exit(EXIT_SUCCESS);
}

int	ft_key(int keycode, t_log *log)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(log->mlx_ptr, log->win_ptr);
		exit(EXIT_SUCCESS);
	}
	// if (keycode == W)
	// {
	// 	if (!(PLAYER == pos_up))
	// 		PLAYER = pos_up;
	// 	if (player_Y + 1 != (MUR))
	// 		go_up;
	// }
	// if (keycode == A)
	// {
	// 	if (!(PLAYER == pos_left))
	// 		PLAYER = pos_left;
	// 	if (player_X- 1 != (MUR))
	// 		go_left;
	// }
	// if (keycode == S)
	// {
	// 	if (!(PLAYER == pos_down))
	// 		PLAYER = pos_down;
	// 	if (player_Y - 1 != (MUR))
	// 		go_down;
	// }
	// if (keycode == D)
	// {
	// 	if (!(PLAYER == pos_right))
	// 		PLAYER = pos_right;
	// 	if (player_X+ 1 != (MUR))
	// 		go_right;
	// }
	return (0);
}

int ft_close(t_log *log)
{
	(void)log;
	mlx_destroy_window(log->mlx_ptr, log->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	t_log	log;

	test_error(argc, argv);
	ft_parsmap(argv[1], &log);
	log.mlx_ptr = mlx_init();
	if (log.mlx_ptr == NULL)
		return (1);
	log.win_ptr = mlx_new_window(log.mlx_ptr, 1200, 800, "so_long");
	if (log.win_ptr == NULL)
		return (1);
	mlx_key_hook(log.win_ptr, ft_key, &log);
	mlx_hook(log.win_ptr, 17, 0, ft_close, &log);
	mlx_loop(log.mlx_ptr);
	return (0);
}
