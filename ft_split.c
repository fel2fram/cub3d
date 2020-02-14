/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 06:04:37 by fde-fram          #+#    #+#             */
/*   Updated: 2019/11/09 18:17:55 by fde-fram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*ft_split(char *s, char c)
{
	int		i;
	int		a;
	char	*tab;

	i = ft_strlen(s) - 1;
	a = 0;
	if (!(tab = ft_calloc(sizeof(char), i + 1)))
		return (NULL);
	while (i >= 0)
	{
		while (s[i] == c)
			i--;
		if (s[i] != '0' && s[i] != '1' && s[i] != '2' && s[i] != 'N'
		&& s[i] != 'S' && s[i] != 'E' && s[i] != 'W')
		{
			free(s);
			free(tab);
			return (NULL);
		}
		if (s[i] != c && s[i])
			tab[a++] = s[i--];
	}
	free(s);
	return (tab);
}
