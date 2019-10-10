/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 09:54:50 by metalium          #+#    #+#             */
/*   Updated: 2019/10/10 12:11:53 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_fgroup *fgroup)
{
	if (key == '5')
		exit(0);
	fgroup->move_y -= (key == 126) ? 20 : 0;
	fgroup->move_y += (key == 125) ? 20 : 0;
	fgroup->move_x -= (key == 123) ? 20 : 0;
	fgroup->move_x += (key == 124) ? 20 : 0;
	fgroup->zoom += (key == 69) ? 10 : 0;
	fgroup->rot += (key == 86) ? 0.05 : 0;
	fgroup->rot -= (key == 88) ? 0.05 : 0;
	if (key == 87)
		fgroup->perspective = (fgroup->perspective == 0) ? 1 : 0;
	fgroup->zoom -= (key == 78 && fgroup->zoom > 10) ? 10 : 0;
	if (key == 91)
		fgroup->scale_z--;
	if (key == 84)
		fgroup->scale_z++;
	render(fgroup);
	return (0);
}

int		read_file(char *file_name, t_fgroup *fgroup)
{
	get_land_height(file_name, fgroup);
	get_land_width(file_name, fgroup);
	land_alocate(fgroup);
	land_fill(file_name, fgroup);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fgroup	*fgroup;

	ft_error(argc, argv[1]);
	fgroup = (t_fgroup*)malloc(sizeof(t_fgroup));
	read_file(argv[1], fgroup);
	fgroup->mlx_ptr = mlx_init();
	fgroup->win_ptr = mlx_new_window(fgroup->mlx_ptr, 1200, 1200, "mlx 42");
	init_fgroup(fgroup);
	render(fgroup);
	mlx_key_hook(fgroup->win_ptr, deal_key, fgroup);
	mlx_loop(fgroup->mlx_ptr);
	return (0);
}
