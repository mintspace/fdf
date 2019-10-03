/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metalium <metalium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 09:54:50 by metalium          #+#    #+#             */
/*   Updated: 2019/10/03 13:21:16 by metalium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, void *data, t_fgroup *fgroup)
{
	ft_printf("%c", key);
	if (key == '5')
		exit (0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fgroup	*fgroup;

	fgroup = (t_fgroup*)malloc(sizeof(t_fgroup));

	fgroup = get_land(**argv, fgroup); // read file

	fgroup->mlx_ptr = mlx_init();
	fgroup->win_ptr = mlx_new_window(fgroup->mlx_ptr, 800, 800, "mlx 42");

	bres_line(10, 30, 500, 540, fgroup);
	mlx_key_hook(fgroup->win_ptr, deal_key, NULL); // NULL -> char map
	mlx_loop(fgroup->mlx_ptr);

	return (0);
}
