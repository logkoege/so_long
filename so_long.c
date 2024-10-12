/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:05:58 by logkoege          #+#    #+#             */
/*   Updated: 2024/10/12 19:36:05 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_log	log;

	log.i = 0;
	log.j = 0;
	log.c = 0;
	log.p = 0;
	log.e = 0;
	log.ct = 0;
	log.nb_of_mv = 0;
	(void)log;
	log.map = ft_strdup("");
	test_error(&log, argc, argv);
	ft_parsmap(argv[1], &log);
	init_mlx(&log);
	mlx_hook(log.win_ptr, 2, 1L << 0, player_intructs, &log);
	mlx_hook(log.win_ptr, 17, 0, ft_close, &log);
	mlx_loop(log.mlx_ptr);
	return (0);
}
