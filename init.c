/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:04:34 by fde-fram          #+#    #+#             */
/*   Updated: 2020/01/21 17:35:06 by fde-fram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	freetexture(char *texture[5])
{
	int i;

	i = -1;
	while (++i < 5)
		free(texture[i]);
}

int		init(t_img *data, char *texture[5], float w, float h)
{
	int i;

	i = -1;
	if (((data->mlx_ptr = mlx_init()) == NULL) || w <= 0 || h <= 0 ||
	(!(data->mlx_win = mlx_new_window(data->mlx_ptr, w, h, "cub3d"))))
		return (-1);
	data->mlx_img = mlx_new_image(data->mlx_ptr, w, h);
	data->addr = (int*)mlx_get_data_addr(data->mlx_img,
		&(data->bpp), &(data->sl), &(data->endian));
	while (++i < 5)
	{
		if (!(data->text[i] = mlx_xpm_file_to_image(data->mlx_ptr, texture[i],
		&(data->width), &(data->height))))
		{
			freeimg(data, i - 1);
			return (-1);
		}
		data->addrimg[i] = data->text[i];
		data->text[i] = (int*)mlx_get_data_addr(data->text[i],
			&(data->bpp), &(data->sl), &(data->endian));
		data->wimg[i] = data->width;
		data->himg[i] = data->height;
	}
	freetexture(texture);
	return (0);
}

void	declare(t_data *d)
{
	int i;

	i = -1;
	while (++i < 256)
		d->key[i] = 0;
	d->cosdevie = cos(d->devie);
	d->sindevie = sin(d->devie);
	d->tandevie = tan(d->devie);
}

int		checknom(char *nom)
{
	int i;

	i = ft_strlen(nom);
	if (i < 4 || nom[i - 1] != 'b' || nom[i - 2] != 'u' || nom[i - 3] != 'c'
	|| nom[i - 4] != '.')
		return (-1);
	return (open(nom, O_RDONLY));
}

char	**remplace(int i, char **res)
{
	char	**res2;

	res2 = ft_calloc(i + 2, sizeof(char*));
	ft_memcpy(res2, res, i + 1);
	free(res);
	return (res2);
}
