# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/01 09:54:57 by metalium          #+#    #+#              #
#    Updated: 2019/10/03 18:43:44 by dbubnov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



FRAEMWORKS=-framework OpenGL -framework AppKit

all:
	gcc *.c libft/libft.a minilibx_macos/libmlx.a $(FRAEMWORKS)
	./a.out test_maps/42.fdf

push:
	git add .
	git status
	git commit -m fdf
	git push
