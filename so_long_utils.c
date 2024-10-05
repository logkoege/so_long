/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:25:02 by logkoege          #+#    #+#             */
/*   Updated: 2024/10/05 18:22:53 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tourmap(char *ligne, t_log *log)
{
	log->tmap[log->j] = ft_strdup(ligne);
	if (log->j == 0 || log->j == log->nbligne -1)
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

void	ft_while_gnl(t_log *log, int fd, char *argv)
{
	char	*ligne;

	fd = open(argv, O_RDONLY);
	while (1)
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

void	ft_size_ligne(int fd, t_log *log)
{
	char	*ligne;
	int		i;

	i = 0;
	log->nbligne = 0;
	while (ligne)
	{
		ligne = get_next_line(fd);
		if (i == 0)
			log->map_x = ft_strlen(ligne);
		if (!ligne)
			break ;
		log->nbligne++;
		free(ligne);
		i = 1;
	}
	if (IMG_HEIGHT * (log->nbligne - 1) > 1080
		|| (log->map_x - 1) * IMG_WIDTH > 1920)
	{
		write(1, "error map trop grande\n", 22);
		exit(EXIT_SUCCESS);
	}
	log->tmap = malloc (sizeof(char *) * (log->nbligne));
	close(fd);
}

void	ft_parsmap(char *argv, t_log *log)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		exit(EXIT_SUCCESS);
	(void)log;
	ft_size_ligne(fd, log);
	ft_while_gnl(log, fd, argv);
	copy_map(log);
	close(fd);
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
