/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:50:53 by logkoege          #+#    #+#             */
/*   Updated: 2024/10/12 19:33:03 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_log *log)
{
	ft_freexit(log, NULL);
	mlx_destroy_window(log->mlx_ptr, log->win_ptr);
	exit(EXIT_SUCCESS);
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
