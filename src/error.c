/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:06:50 by dbubnov           #+#    #+#             */
/*   Updated: 2019/10/07 18:46:14 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_error(int argc, char *argv)
{
	if (argc != 2)
	{
		ft_printf("%s", "use *.fdf file as argument.\n");
		exit(1);
	}
	if (!(ft_strstr(argv, ".fdf")))
	{
		ft_printf("%s", "It's not an fdf file.\n");
		exit(1);
	}
	return (1);
}

int		ft_error_fd(int fd)
{
	if (fd < 0)
	{
		ft_printf("%s", "Error reading file or file does not exist...\n");
		exit(1);
	}
	return (1);
}
