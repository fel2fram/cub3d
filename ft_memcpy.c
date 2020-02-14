/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmiraill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:14:21 by fmiraill          #+#    #+#             */
/*   Updated: 2020/01/21 16:45:17 by fde-fram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void			**tempdst;
	void			**tempsrc;
	size_t			i;

	i = 0;
	tempdst = (void **)dst;
	tempsrc = (void **)src;
	if (src == NULL && dst == NULL)
		return (0);
	while (i < n)
	{
		tempdst[i] = tempsrc[i];
		i++;
	}
	return (dst);
}

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
