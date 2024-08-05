/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 02:35:41 by logkoege          #+#    #+#             */
/*   Updated: 2024/07/30 20:17:30 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

void	ft_bzero(void *s1, size_t n);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(char *str);
char	*ft_strdup(char *s1);
int		ft_free(char *str);
char	*copy_cat(char *dest, char *dbu, char *fin);
char	*ft_strncpy(char *str, char *s2, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_split(char *tab, char c);

#endif