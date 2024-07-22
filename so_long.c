/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:05:58 by logkoege          #+#    #+#             */
/*   Updated: 2024/07/20 15:05:39 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_parsmap(char *argv, t_log *log)
{
	int	fd;
	char	*ligne;
	
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		mlx_destroy_window(log->mlx_ptr, log->win_ptr);
		exit(EXIT_SUCCESS);
	}
	while(1)
	{
		ligne = get_next_line(fd);
		if (!ligne)
			break ;
		log->map = ft_strjoin(log->map, ligne);
		free(ligne);
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
	// 	if (!(p == pos_up))
	// 		p = pos_up;
	// 	if (y + 1 != (MUR))
	// 		go_up;
	// }
	// if (keycode == A)
	// {
	// 	if (!(p == pos_left))
	// 		p = pos_left;
	// 	if (x - 1 != (MUR))
	// 		go_left;
	// }
	// if (keycode == S)
	// {
	// 	if (!(p == pos_down))
	// 		p = pos_down;
	// 	if (y - 1 != (MUR))
	// 		go_down;
	// }
	// if (keycode == D)
	// {
	// 	if (!(p == pos_right))
	// 		p = pos_right;
	// 	if (x + 1 != (MUR))
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
