/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:25:02 by logkoege          #+#    #+#             */
/*   Updated: 2024/08/05 21:36:07 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tourmap(char *ligne, t_log *log)
{
	log->tmap[log->j] = ft_strdup(ligne);
	if (log->tmap[log->j][log->i] == log->tmap[0][0] ||
		log->tmap[log->j][log->i] == log->tmap[log->nbligne - 1][log->i])
	{
		while (log->tmap[log->j][log->i] != '\n' && log->tmap[log->j][log->i])
		{
			if (log->tmap[log->j][log->i] != 49)
				ft_freexit(ligne);
			log->i++;
		}
	}
	else
	{
		if (log->tmap[log->j][0] != '1' ||
			log->tmap [log->j][log->map_x - 2] != '1')
				ft_freexit(ligne);
	}
	free(log->tmap[log->j]);
	if (log->j != log->nbligne)
		log->j++;
}

void	ft_while(t_log *log, char *ligne, int fd)
{
	while (1)
	{
		ligne = get_next_line(fd);
		if (!ligne)
			break ;
		if (log->map_x != ft_strlen(ligne))
			ft_freexit(ligne);
		//tourmap(ligne, log);
		log->map = ft_strjoin(log->map, ligne);
		free(ligne);
		log->map_y++;
	}
}

void	ft_tligne(char *ligne, int fd, t_log *log)
{
	log->nbligne = 0;
	while (1)
	{
		log->nbligne++;
		ligne = get_next_line(fd);
		if (!ligne)
			break ;
		free(ligne);
	}
	log->tmap = malloc (sizeof(char *) * (log->nbligne));
	close(fd);
}

void	ft_freexit(char *str)
{
	free(str);
	exit(EXIT_SUCCESS);
}
