/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:05:58 by logkoege          #+#    #+#             */
/*   Updated: 2024/07/12 18:58:01 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	test_error(int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
		return (-1);
	len = ft_strlen(argv[1]);
	if (argv[1][len] == 'r' && argv[1][len - 1] == 'e' && argv[1][len - 2] == 'b' && argv[1][len - 3] == '.')
		return (1);
	return (0);
}

int	ft_key(int keycode, t_log *log)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(log->mlx_ptr, log->win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 119(w))
	{
		
	}
	if (keycode == 97(a))
	{
		
	}
	if (keycode == 115(s))
	{
		
	}
	if (keycode == 100(d))
	{
		
	}
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
	int	fd;

	test_error(argc, argv)
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd);
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
