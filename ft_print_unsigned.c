/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:01:53 by logkoege          #+#    #+#             */
/*   Updated: 2024/05/18 18:52:17 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_len(unsigned int n)
{
	if (n >= 1000000000)
		return (10);
	else if (n >= 100000000)
		return (9);
	else if (n >= 10000000)
		return (8);
	else if (n >= 1000000)
		return (7);
	else if (n >= 100000)
		return (6);
	else if (n >= 10000)
		return (5);
	else if (n >= 1000)
		return (4);
	else if (n >= 100)
		return (3);
	else if (n >= 10)
		return (2);
	else
		return (1);
}

void	ft_print_rec(unsigned int n)
{
	if (n >= 10)
	{
		ft_print_rec(n / 10);
	}
	ft_putchar_fd(n % 10 + 48, 1);
}

int	ft_print_unsigned(unsigned int n)
{
	ft_print_rec(n);
	return (ft_unsigned_len(n));
}
