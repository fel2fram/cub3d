/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmiraill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:40:39 by fmiraill          #+#    #+#             */
/*   Updated: 2019/11/09 15:58:45 by fmiraill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str, char c, int mult)
{
	int	i;
	int a;
	int nbr;

	nbr = 0;
	i = 0;
	a = 0;
	if (str[a] == c)
		a++;
	while (mult && str[a] == c)
		a++;
	while (str[a + i] >= '0' && str[a + i] <= '9')
	{
		nbr *= 10;
		nbr += (int)str[a + i] - '0';
		i++;
	}
	if (i > 0 && a > 0)
		return (nbr);
	else
		return (-1);
}
