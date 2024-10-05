/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:05:58 by logkoege          #+#    #+#             */
/*   Updated: 2024/10/05 03:15:37 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_parsmap(char *argv, t_log *log)
{
	int		fd;
	char	*ligne;
	(void)ligne;

	ligne = NULL;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		exit(EXIT_SUCCESS);
	(void)log;
	ft_size_ligne(fd, log);
	ft_while_gnl(log, fd, argv);
	copy_map(log);
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
	(void)argc;
	(void)argv;
	t_log	log;

	log.i = 0;
	log.j = 0;
	log.c = 0;
	log.p = 0;
	log.e = 0;
	(void)log;
	log.map = ft_strdup("");
	test_error(argc, argv);
	ft_parsmap(argv[1], &log);
	init_mlx(&log);
	mlx_key_hook(log.win_ptr, ft_key, &log);
	mlx_hook(log.win_ptr, 17, 0, ft_close, &log);
	mlx_loop(log.mlx_ptr);
	return (0);
}
