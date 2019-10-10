/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 09:54:50 by metalium          #+#    #+#             */
/*   Updated: 2019/10/09 12:39:02 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_fgroup *fgroup)
{
	if (key == '5')
		exit (0);
	if (key == 126)
		fgroup->move_y -= 20;
	if (key == 125)
		fgroup->move_y += 20;
	if (key == 123)
		fgroup->move_x -= 20;
	if (key == 124)
		fgroup->move_x += 20;
	if (key == 87)
		fgroup->perspective = (fgroup->perspective == 0) ? 1 : 0;
	if (key == 69)
		fgroup->zoom += 10;
	if (key == 78 && fgroup->zoom > 10)
		fgroup->zoom -= 10;
	if (key == 91)
		fgroup->scale_z--;
	if (key == 84)
		fgroup->scale_z++;
	if (key == 86)
		fgroup->rot += 0.05;
	if (key == 88)
		fgroup->rot -= 0.05;
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
