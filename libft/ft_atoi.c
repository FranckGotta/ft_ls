/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgotta <frgotta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 19:12:34 by frgotta           #+#    #+#             */
/*   Updated: 2017/11/09 11:44:06 by frgotta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int neg;
	int nb;

	nb = 0;
	neg = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		neg = 1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9' && *nptr)
	{
		nb = nb * 10;
		nb = nb + *nptr - '0';
		nptr++;
	}
	if (neg == 1)
		return (-nb);
	return (nb);
}
