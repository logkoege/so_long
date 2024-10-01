/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:25:02 by logkoege          #+#    #+#             */
/*   Updated: 2024/10/01 00:35:50 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tourmap(char *ligne, t_log *log)
{
	log->tmap[log->j] = ft_strdup(ligne);
	if (log->j == 0 || log->j == log->nbligne - 1)
	{
		log->i = 0;
		while (log->tmap[log->j][log->i] != '\n' && log->tmap[log->j][log->i])
		{
			printf("%c", log->tmap[log->j][log->i]);
			if (log->tmap[log->j][log->i] != 49)
				ft_freexit(log);
			log->i++;
		}
		printf("%c", log->tmap[log->j][log->i]);
	}
	else
	{
		if (log->tmap[log->j][0] != '1' ||
			log->tmap [log->j][log->map_x - 2] != '1')
			ft_freexit(log);
		ft_check_cpe(log);
	}
	if (log->j != log->nbligne)
		log->j++;
}

void	ft_while_gnl(t_log *log, char *ligne, int fd)
{
	while (ligne)
	{
		ligne = get_next_line(fd);
		if (!ligne)
			break ;
		if (log->map_x != ft_strlen(ligne))
			ft_freexit(log);
		tourmap(ligne, log);
		log->map = ft_strjoin(log->map, ligne);
		free(ligne);
		log->map_y++;
	}
	if (log->c < 1 || log->p != 1 || log->e != 1)
	{
		printf("probleme a cause du :\n");
		printf("nombre d'item = %i doit etre > 1\n ou \n", log->c);
		printf("nombre de joueur = %i doit etre = a 1\n ou \n", log->p);
		printf("nombre de nombre de sortie = %i doit etre = a 1\n", log->e);
		exit(EXIT_SUCCESS);
	}
}

void	ft_size_ligne(char *ligne, int fd, t_log *log)
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

void	ft_freexit(t_log *log)
{
	int	j;

	j = 0;
	write(1, "Error\n", 6);
	if (log->tmap)
	{
		while (log->tmap[log->j])
		{
			free(log->tmap[log->j]);
			log->j--;
		}
		free(log->tmap);
	}
	if (log->copy_map)
	{
		while (log->copy_map[log->j])
			free(log->copy_map[j++]);
		free(log->copy_map);
	}
	exit(EXIT_SUCCESS);
}

void	ft_check_cpe(t_log *log)
{
	int	t;

	t = 0;
	while (t <= log->map_x)
	{
		printf("%c", log->tmap[log->j][t]);
		if (log->tmap[log->j][t] == 'C')
			log->c++;
		if (log->tmap[log->j][t] == 'P')
			log->p++;
		if (log->tmap[log->j][t] == 'E')
			log->e++;
		t++;
	}
}
