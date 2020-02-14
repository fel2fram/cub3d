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

int		joueur_pos(const char *s)
{
	int	i;
	int temp;

	i = 0;
	temp = -2;
	while (s[i])
	{
		if (s[i] == 'S' || s[i] == 'N' || s[i] == 'W' || s[i] == 'E')
		{
			if (temp != -2)
				return (-1);
			else
				temp = i;
		}
		i++;
	}
	return (temp);
}

int		getmap(t_data *d, int i, char **ligne)
{
	int pos;

	if (!(*ligne = ft_split(*ligne, ' ')))
		return (-1);
	if ((pos = joueur_pos(*ligne)) != -2)
	{
		if (pos == -1 || d->joueur[0] || d->joueur[1])
			return (-1);
		d->joueur[0] = i + 0.5;
		d->joueur[1] = pos + 0.5;
		((*ligne)[pos] == 'S') ? d->devie = 0 : 0;
		((*ligne)[pos] == 'W') ? d->devie = PI / 2 : 0;
		((*ligne)[pos] == 'E') ? d->devie = -PI / 2 : 0;
		((*ligne)[pos] == 'N') ? d->devie = PI : 0;
		(*ligne)[pos] = '0';
	}
	if (!d->largs[1])
		d->largs[1] = ft_strlen((char *)*ligne) + 1;
	else if (d->largs[1] != ft_strlen((char *)*ligne) + 1)
		return (-1);
	return (0);
}

char	**mappe(char *nom, char *texture[4], t_data *d)
{
	char	**res;
	int		fd;
	int		i;
	int		map;

	if ((fd = checknom(nom)) <= 0)
		return (NULL);
	i = 0;
	map = 0;
	res = ft_calloc(1, sizeof(char*));
	while (get_next_line(fd, res + i))
	{
		free((!map && ((map = pref(d, texture, res[i])) <= 0)) ? res[i] : 0);
		free(map < 0 ? res : 0);
		if (map < 0 || (map && getmap(d, i, res + i) < 0 && freemurs(res, i)))
			return (NULL);
		res = (map ? remplace(i++, res) : res);
	}
	d->largs[0] = i;
	if (((!check_closed(res, d->largs) || !d->joueur[0] || !d->joueur[1]))
	&& freemurs(res, i))
		return (NULL);
	return (res);
}

float	ab(float a)
{
	if (a > 0)
		return (a);
	return (-a);
}

int		main(int ac, char **av)
{
	t_data	d;
	char	*texture[5];

	declare0(texture, &d);
	if ((ac != 2 && ac != 3) || !(d.lmurs = mappe(av[1], texture, &d)))
	{
		freetexture(texture);
		printf("Error\nErreur dans l'ouverture de la map.\n");
		system("leaks cub3d");
		return (-1);
	}
	declare(&d);
	if (d.coulsol < 0 || d.coulpla < 0 || init(&d.data, texture, d.w, d.h) < 0)
	{
		freemurs(d.lmurs, d.largs[0]);
		freetexture(texture);
		printf("Error\nErreur dans l'initialisation fenetre et textures.\n");
		system("leaks cub3d");
		return (-1);
	}
	if (ac == 3 && (ft_strncmp(av[2], "-save", 5) || !save_bmp(&d)))
	{
		printf("Error\nErreur dans le screenshot.\n");
		system("leaks cub3d");
		return (-1);
	}
	return (mlx_boucle(&d, ac));
}
