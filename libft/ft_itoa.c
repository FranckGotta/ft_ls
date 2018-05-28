/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgotta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:17:54 by frgotta           #+#    #+#             */
/*   Updated: 2017/11/08 18:50:10 by frgotta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_is_negative(int *c, int *neg)
{
	if (*c < 0)
	{
		*c *= -1;
		*neg = 1;
	}
}

char			*ft_itoa(int c)
{
	char	*str;
	int		i;
	int		nb;
	int		neg;

	if (c == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 1;
	neg = 0;
	ft_is_negative(&c, &neg);
	nb = c;
	while (c /= 10)
		i++;
	i += neg;
	if ((str = (char *)malloc(sizeof(*str) * i + 1)) == NULL)
		return (NULL);
	str[i] = '\0';
	while (i--)
	{
		str[i] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
