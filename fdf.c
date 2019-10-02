/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 09:54:50 by metalium          #+#    #+#             */
/*   Updated: 2019/10/01 19:44:07 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, void *data)
{
	ft_printf("%c", key);
	if (key == '5')
		exit (0);
	return (0);
}

int		main(void)
{
	

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1200, 1200, "mlx 42");
	// mlx_pixel_put(mlx_ptr, win_ptr, 200, 200, 0x34e8eb);
	bres_line(10,300, 300,300);
	mlx_key_hook(win_ptr, deal_key, NULL); // NULL -> char map
	mlx_loop(mlx_ptr);
	
	return (0);
}
