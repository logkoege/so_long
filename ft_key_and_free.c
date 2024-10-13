/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:50:53 by logkoege          #+#    #+#             */
/*   Updated: 2024/10/13 21:00:20 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_log *log)
{
	ft_freexit(log, "x\n");
	return (0);
}

void	ft_freexit(t_log *log, char *msg)
{
	int	i;
	int	j;

	j = -1;
	i = -1;
	while (msg[++i])
		write(1, &msg[i], 1);
	if (log->tmap)
	{
		while (++j < log->nbligne)
			free(log->tmap[j]);
		free(log->tmap);
	}
	if (log->copy_map)
	{
		j = -1;
		while (++j < log->nbligne)
			free(log->copy_map[j]);
		free(log->copy_map);
	}
	destroy_mlx(log);
	exit(EXIT_SUCCESS);
}

void	test_error(t_log *log, int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
		ft_freexit(log, "error: argc != 2\n");
	len = ft_strlen(argv[1]);
	if (!(argv[1][len - 1] == 'r' && argv[1][len - 2] == 'e' &&
	argv[1][len - 3] == 'b' && argv[1][len - 4] == '.'))
		ft_freexit(log, "error: .ber\n");
}

void	init_var(t_log *log)
{
	log->player = 0;
	log->i = 0;
	log->j = 0;
	log->c = 0;
	log->p = 0;
	log->e = 0;
	log->ct = 0;
	log->nb_of_mv = 0;
	log->tmap = NULL;
	log->copy_map = NULL;
	log->mlx_ptr = NULL;
	log->map = NULL;
	log->player_up = NULL;
	log->player_down = NULL;
	log->player_right = NULL;
	log->player_left = NULL;
	log->bed = NULL;
	log->grass = NULL;
	log->tree = NULL;
	log->master_ball = NULL;
	log->map_x = 0;
}
