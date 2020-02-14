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

void	d_cote(t_data *d, double gauche)
{
	if ('1' != d->lmurs[(int)(d->joueur[0] + gauche * d->cosdevie)]
	[(int)(d->joueur[1])])
		d->joueur[0] += gauche * d->cosdevie;
	if ('1' != d->lmurs[(int)(d->joueur[0])]
	[(int)(d->joueur[1] + gauche * d->sindevie)])
		d->joueur[1] += gauche * d->sindevie;
}

void	d_avant(t_data *d, double haut)
{
	if ('1' != d->lmurs[(int)(d->joueur[0] + haut * d->sindevie)]
	[(int)(d->joueur[1])])
		d->joueur[0] += haut * d->sindevie;
	if ('1' != d->lmurs[(int)(d->joueur[0])]
	[(int)(d->joueur[1] - haut * d->cosdevie)])
		d->joueur[1] -= haut * d->cosdevie;
}

void	d_angle(t_data *d, double gauche)
{
	d->devie += gauche;
	d->cosdevie = cos(d->devie);
	d->sindevie = sin(d->devie);
	d->tandevie = tan(d->devie);
}

int		dr(t_data *d)
{
	if ((d->key[13] || d->key[126] || d->key[1] || d->key[125]) &&
	(!((d->key[13] || d->key[126]) && (d->key[1] || d->key[125]))))
		d_cote(d, (d->key[13] || d->key[126]) ? DEPL : -DEPL);
	if ((d->key[0] || d->key[2]) && !(d->key[0] && d->key[2]))
		d_avant(d, d->key[0] ? DEPL : -DEPL);
	if ((d->key[124] || d->key[123]) && !(d->key[124] && d->key[123]))
		d_angle(d, d->key[124] ? ANGLE : -ANGLE);
	print_screen(d);
	return (0);
}
