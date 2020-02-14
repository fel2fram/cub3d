/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 09:31:13 by fde-fram          #+#    #+#             */
/*   Updated: 2019/11/18 16:17:53 by fde-fram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	affiche(char *buf, char **line)
{
	char *temp2;

	temp2 = *line;
	if (!(*line = ft_strjoin(*line, buf)))
	{
		free(temp2);
		return (-1);
	}
	free(temp2);
	return (1);
}

int	affiche_tout(char *buf, char **line, int fd)
{
	if (affiche(buf, line) == -1)
		return (-1);
	ft_bzero(buf, BUFFER_SIZE);
	return (read(fd, buf, BUFFER_SIZE));
}

int	affiche_fin(char *buf, char **line, char *temp)
{
	*temp = '\0';
	if (affiche(buf, line) == -1)
		return (-1);
	ft_memmove(buf, temp + 1, BUFFER_SIZE + 1 - (int)(temp - buf));
	return (1);
}

int	fin(char **buf, int err)
{
	free(*buf);
	*buf = NULL;
	return (err);
}

int	get_next_line(int fd, char **line)
{
	static char			*buf = NULL;
	char				*temp;
	int					err;

	if ((err = -1) && (fd < 0 || !line || BUFFER_SIZE < 1
	|| !(*line = ft_calloc(1, sizeof(char)))
	|| (!buf && (!(buf = ft_calloc(BUFFER_SIZE + 2, sizeof(char)))
	|| (err = read(fd, buf, BUFFER_SIZE)) <= 0))))
		return (fin(&buf, err));
	while (!(temp = ft_strchr(buf, '\n')))
		if ((err = affiche_tout(buf, line, fd)) <= 0)
			return (fin(&buf, err));
	if ((err = affiche_fin(buf, line, temp)) <= 0)
		return (fin(&buf, err));
	return (1);
}
