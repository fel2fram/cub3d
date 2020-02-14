/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:04:34 by fde-fram          #+#    #+#             */
/*   Updated: 2019/10/08 19:56:40 by fde-fram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		mlx_boucle(t_data *d, int ac)
{
	if (ac == 2)
	{
		mlx_hook(d->data.mlx_win, 2, 1L << 0, &key_press, (void*)(d));
		mlx_hook(d->data.mlx_win, 3, 1L << 1, &key_release, (void*)(d));
		mlx_hook(d->data.mlx_win, 17, 1L << 0, &clickescape, (void*)(d));
		mlx_loop_hook(d->data.mlx_ptr, &dr, (void*)(d));
		mlx_loop(d->data.mlx_ptr);
	}
	else
	{
		clickescape(d);
	}
	return (1);
}

void	declare0(char *texture[5], t_data *d)
{
	int i;

	i = -1;
	while (++i < 5)
		texture[i] = 0;
	d->joueur[0] = 0;
	d->joueur[1] = 0;
	d->h = -1;
	d->w = -1;
	d->coulsol = -1;
	d->coulpla = -1;
}
