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

int		r(float *hauteur, float *largeur, char *ligne)
{
	int j;

	j = 1;
	*largeur = ft_atoi(ligne + j, ' ', 1);
	if (*largeur == -1)
		return (-1);
	if (*largeur > 2560)
		*largeur = 2560;
	while (ligne[j] == ' ')
		j++;
	while (ligne[j] >= '0' && ligne[j] <= '9')
		j++;
	*hauteur = ft_atoi(ligne + j, ' ', 1);
	if (*hauteur == -1)
		return (-1);
	if (*hauteur > 1320)
		*hauteur = 1320;
	while (ligne[j] == ' ')
		j++;
	while (ligne[j] >= '0' && ligne[j] <= '9')
		j++;
	if (ligne[j])
		return (-1);
	return (0);
}

int		fc(int *coul, char *ligne)
{
	int j;
	int i;
	int res;

	j = 1;
	i = -1;
	if (*coul != -1)
		return (-1);
	*coul = 0;
	while (++i < 3)
	{
		if ((res = ft_atoi(ligne + j, (i == 0 ? ' ' : ','), (i == 0))) < 0 ||
		res > 255)
			return (-1);
		*coul = *coul * 256 + res;
		while (ligne[j] == (i == 0 ? ' ' : ','))
			j++;
		while (ligne[j] >= '0' && ligne[j] <= '9')
			j++;
	}
	if (ligne[j])
		return (-1);
	return (0);
}

int		nsews(char **texture, char *ligne)
{
	int j;

	j = 0;
	while (ligne[j] == ' ')
		j++;
	if (j == 0 || *texture)
		return (-1);
	*texture = ft_strdup(ligne + j);
	return (0);
}

int		check_closed(char **res, int *largs)
{
	int i;
	int j;

	i = -1;
	while (++i < largs[0])
	{
		j = 0;
		if (!(i == 0 || i == largs[0] - 1))
		{
			if (res[i][0] != '1' || res[i][largs[1] - 2] != '1')
				return (0);
		}
		else
			while (j < largs[1] - 1)
				if (res[i][j++] != '1')
					return (0);
	}
	return (1);
}

int		pref(t_data *d, char *texture[4], char *ligne)
{
	if (!ligne[0])
		return (0);
	else if (ligne[0] == 'R')
		return (r(&(d->h), &(d->w), ligne));
	else if (ligne[0] == 'F' || ligne[0] == 'C')
		return (fc(ligne[0] == 'F' ? &(d->coulsol) : &(d->coulpla), ligne));
	else if (ligne[0] == 'N' && ligne[1] == 'O')
		return (nsews(texture, ligne + 2));
	else if (ligne[0] == 'S' && ligne[1] == 'O')
		return (nsews(texture + 1, ligne + 2));
	else if (ligne[0] == 'W' && ligne[1] == 'E')
		return (nsews(texture + 3, ligne + 2));
	else if (ligne[0] == 'E' && ligne[1] == 'A')
		return (nsews(texture + 2, ligne + 2));
	else if (ligne[0] == 'S')
		return (nsews(texture + 4, ligne + 1));
	else
		return (1);
	return (0);
}
