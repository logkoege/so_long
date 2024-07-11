/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 05:42:46 by logkoege          #+#    #+#             */
/*   Updated: 2024/07/06 05:43:18 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int main(void)
{
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    if (!mlx_ptr)
    {
        printf("%s", "L");
        return (1);
    }
    win_ptr = mlx_new_window(mlx_ptr, 1600, 900, "So Long");
    if (!win_ptr)
    {
        printf("%s", "L_F");
        return (1);
    }
    mlx_loop(mlx_ptr);
    return (0);
}
