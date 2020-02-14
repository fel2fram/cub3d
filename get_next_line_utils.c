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

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tdst;
	unsigned char	*tsrc;

	tdst = (unsigned char *)dst;
	tsrc = (unsigned char *)src;
	i = 0;
	if (tdst == NULL && tsrc == NULL)
		return (0);
	if (tsrc < tdst)
		while (i < len)
		{
			i++;
			tdst[len - i] = tsrc[len - i];
		}
	else
		while (i < len)
		{
			tdst[i] = tsrc[i];
			i++;
		}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		a;
	char	*res;

	i = 0;
	a = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	while (s2[a++] != '\0')
		i++;
	if (!(res = malloc((i + 1) * sizeof(char))))
		return (NULL);
	res[i] = '\0';
	i = 0;
	a = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[a])
		res[i++] = s2[a++];
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*bzer;
	unsigned int	i;

	i = 0;
	bzer = (unsigned char*)s;
	while (i < n)
	{
		bzer[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	if (!(s = (char *)malloc(sizeof(char) * (nmemb * size))))
		return (0);
	while (i < nmemb * size)
	{
		s[i] = 0;
		i++;
	}
	return ((void *)s);
}
