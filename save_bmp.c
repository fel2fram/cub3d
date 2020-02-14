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

static void
	set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

int
	write_bmp_header(int fd, t_data *d, int filesize)
{
	int				i;
	unsigned char	bmpfileheader[54];

	i = 0;
	while (i < 54)
		bmpfileheader[i++] = (unsigned char)(0);
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	bmpfileheader[3] = (unsigned char)(1);
	set_int_in_char(bmpfileheader + 2, filesize);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	set_int_in_char(bmpfileheader + 18, d->w);
	set_int_in_char(bmpfileheader + 22, d->h);
	bmpfileheader[26] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
	set_int_in_char(bmpfileheader + 34, filesize - 54);
	set_int_in_char(bmpfileheader + 38, 2834);
	set_int_in_char(bmpfileheader + 42, 2834);
	return (!(write(fd, bmpfileheader, 54) < 0));
}

static int
	get_color(t_data *d, int x, int y)
{
	int	color;

	color = d->data.addr[(int)d->w * ((int)d->h - 1 - y) + x];
	return ((color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF));
}

int
	write_bmp_data(int file, t_data *d, int pad)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					i;
	int					j;
	int					color;

	i = 0;
	while (i < (int)d->h)
	{
		j = 0;
		while (j < (int)d->w)
		{
			color = get_color(d, j, i);
			if (write(file, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(file, &zero, pad) < 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int
	save_bmp(t_data *d)
{
	int	fd;
	int	filesize;
	int	pad;

	pad = (4 - ((int)d->w * 3) % 4) % 4;
	filesize = 54 + (3 * ((int)d->w + pad) * (int)d->h);
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT
								| O_TRUNC | O_APPEND)) < 0)
		return (0);
	print_screen(d);
	if (!write_bmp_header(fd, d, filesize))
		return (0);
	if (!write_bmp_data(fd, d, pad))
		return (0);
	close(fd);
	return (1);
}
