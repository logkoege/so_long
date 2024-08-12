/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:05:58 by logkoege          #+#    #+#             */
/*   Updated: 2024/08/08 16:23:29 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_parsmap(char *argv, t_log *log)
{
	int		fd;
	char	*ligne;

	ligne = "  ";
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(EXIT_SUCCESS);
	ft_size_ligne(ligne, fd, log);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(EXIT_SUCCESS);
	ligne = get_next_line(fd);
	log->map_x = ft_strlen(ligne);
	tourmap(ligne, log);
	log->map = ft_strjoin(log->map, ligne);
	free(ligne);
	log->map_y = 1;
	ft_while_gnl(log, ligne, fd);
	free(log->tmap);
	close(fd);
}

void	test_error(int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
		exit(EXIT_FAILURE);
	len = ft_strlen(argv[1]);
	if (argv[1][len - 1] == 'r' && argv[1][len - 2] == 'e' &&
	argv[1][len - 3] == 'b' && argv[1][len - 4] == '.')
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
	return (0);
}

int	ft_close(t_log *log)
{
	mlx_destroy_window(log->mlx_ptr, log->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	t_log	log;

	log.i = 0;
	log.j = 0;
	test_error(argc, argv);
	ft_parsmap(argv[1], &log);
	log.mlx_ptr = mlx_init();
	if (log.mlx_ptr == NULL)
		return (1);
	log.win_ptr = mlx_new_window(log.mlx_ptr, 1600, 1000, "so_long");
	if (log.win_ptr == NULL)
		return (1);
	mlx_key_hook(log.win_ptr, ft_key, &log);
	mlx_hook(log.win_ptr, 17, 0, ft_close, &log);
	mlx_loop(log.mlx_ptr);
	return (0);
}
	// if (keycode == W)
	// {
	// 	if (!(PLAYER == pos_up))
	// 		PLAYER = pos_up;
	// 	if (player_Y + 1 != (MUR))
	// 		player_y++;
	// }
	// if (keycode == A)
	// {
	// 	if (!(PLAYER == pos_left))
	// 		PLAYER = pos_left;
	// 	if (player_X- 1 != (MUR))
	// 		player_x--;
	// }
	// if (keycode == S)
	// {
	// 	if (!(PLAYER == pos_down))
	// 		PLAYER = pos_down;
	// 	if (player_Y - 1 != (MUR))
	// 		player_y--;
	// }
	// if (keycode == D)
	// {
	// 	if (!(PLAYER == pos_right))
	// 		PLAYER = pos_right;
	// 	if (player_X+ 1 != (MUR))
	// 		player_x++;
	// }