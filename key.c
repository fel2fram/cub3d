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

int		freemurs(char **res, int i)
{
	while (i >= 0)
	{
		free(res[i]);
		i--;
	}
	free(res);
	return (1);
}

void	freeimg(t_img *data, int i)
{
	while (i >= 0)
		mlx_destroy_image(data->mlx_ptr, data->addrimg[i--]);
	mlx_destroy_image(data->mlx_ptr, data->mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
}

int		clickescape(t_data *d)
{
	freeimg(&(d->data), 4);
	freemurs(d->lmurs, d->largs[0]);
	system("leaks cub3d");
	exit(0);
}

int		key_press(int keycode, t_data *d)
{
	int i;

	i = 0;
	d->key[keycode] = 1;
	if (keycode == 53)
		clickescape(d);
	return (0);
}

int		key_release(int keycode, t_data *d)
{
	d->key[keycode] = 0;
	return (0);
}
