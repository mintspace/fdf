/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 09:54:50 by metalium          #+#    #+#             */
/*   Updated: 2019/10/02 18:42:52 by dbubnov          ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	int			fd;
	t_fgroup	*fgroup;

	fd = 0;
	fgroup = (t_fgroup*)malloc(sizeof(t_fgroup));
		
	get_land(); // read file

	fgroup->mlx_ptr = mlx_init();
	fgroup->win_ptr = mlx_new_window(fgroup->mlx_ptr, 800, 800, "mlx 42");
	
	bres_line(10, 30, 500, 540, fgroup);
	mlx_key_hook(fgroup->win_ptr, deal_key, NULL); // NULL -> char map
	mlx_loop(fgroup->mlx_ptr);
	
	return (0);
}
