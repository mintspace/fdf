/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 09:54:50 by metalium          #+#    #+#             */
/*   Updated: 2019/10/04 12:42:37 by dbubnov          ###   ########.fr       */
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

	read_file(argv[1], fgroup);

	// ---------------------------

	// fgroup->mlx_ptr = mlx_init();
	// fgroup->win_ptr = mlx_new_window(fgroup->mlx_ptr, 800, 800, "mlx 42");

	// bres_line(10, 30, 500, 540, fgroup);
	// mlx_key_hook(fgroup->win_ptr, deal_key, NULL); // NULL -> char map
	// mlx_loop(fgroup->mlx_ptr);

	// ---------------------------

	int i;

	i = 0;
	// ft_printf("hight : %d\n", fgroup->land_height);
	// ft_printf("width : %d\n", fgroup->land_width);
	
	ft_printf("first_line : %s\n", fgroup->land[0]);

	return (0);
}
