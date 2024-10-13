/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:25:02 by logkoege          #+#    #+#             */
/*   Updated: 2024/10/13 20:44:21 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tourmap(char *ligne, t_log *log)
{
	log->tmap[log->j] = ft_strdup(ligne);
	if (log->j == 0 || log->j == log->nbligne -1)
	{
		log->i = 0;
		while (log->tmap[log->j][log->i] != '\n'
			&& log->tmap[log->j][log->i])
		{
			if (log->tmap[log->j][log->i] != 49)
				log->ct++;
			log->i++;
		}
	}
	else
	{
		if (log->tmap[log->j][0] != '1' ||
			log->tmap [log->j][log->map_x - 2] != '1')
			log->ct++;
		ft_check_cpe(log);
	}
	if (log->j != log->nbligne)
		log->j++;
}

void	ft_while_gnl(t_log *log, int fd, char *argv)
{
	char	*ligne;

	fd = open(argv, O_RDONLY);
	while (1)
	{
		ligne = get_next_line(fd);
		if (!ligne)
			break ;
		tourmap(ligne, log);
		log->map = ft_strjoin(log->map, ligne);
		free(ligne);
		log->map_y++;
	}
}

void	ft_size_ligne(int fd, t_log *log)
{
	char	*ligne;
	int		i;

	i = 0;
	log->nbligne = 0;
	ligne = NULL;
	while (1)
	{
		ligne = get_next_line(fd);
		if (i == 0)
			log->map_x = ft_strlen(ligne);
		if (!ligne)
			break ;
		if (ft_strlen(ligne) != log->map_x)
			i = 500;
		log->nbligne++;
		free(ligne);
		i++;
	}
	if (i > 500)
		ft_freexit(log, "error: map x\n");
	log->tmap = malloc (sizeof(char *) * (log->nbligne));
	close(fd);
}

void	ft_parsmap(char *argv, t_log *log)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_freexit(log, "error: invalid fd\n");
	ft_size_ligne(fd, log);
	ft_while_gnl(log, fd, argv);
	if (log->ct > 0)
		ft_freexit(log, "error : non vvalid map\n");
	if (log->c < 1 || log->p != 1 || log->e != 1)
		ft_freexit(log, "error: C, P, E\n");
	copy_map(log);
	close(fd);
}

void	ft_check_cpe(t_log *log)
{
	int	t;

	t = 0;
	while (t <= log->map_x)
	{
		if (log->tmap[log->j][t] == 'C')
			log->c++;
		if (log->tmap[log->j][t] == 'P')
			log->p++;
		if (log->tmap[log->j][t] == 'E')
			log->e++;
		t++;
	}
}
