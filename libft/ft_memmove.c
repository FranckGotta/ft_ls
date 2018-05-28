/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgotta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:30:46 by frgotta           #+#    #+#             */
/*   Updated: 2017/11/09 10:55:24 by frgotta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	i = 0;
	if (s1 > s2)
	{
		while (len--)
			*(s1 + len) = *(s2 + len);
	}
	else
	{
		while (i < len)
		{
			*(s1 + i) = *(s2 + i);
			i++;
		}
	}
	return (dst);
}
