/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgotta <frgotta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 15:02:35 by frgotta           #+#    #+#             */
/*   Updated: 2017/11/12 17:58:58 by frgotta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	oct;
	size_t			i;

	str = s;
	oct = c;
	i = 0;
	while (i < n)
	{
		str[i] = oct;
		i++;
	}
	return ((void *)s);
}
