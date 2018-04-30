/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgotta <frgotta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 17:19:15 by frgotta           #+#    #+#             */
/*   Updated: 2017/11/10 12:36:36 by frgotta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest1;
	const char		*src1;

	dest1 = dest;
	src1 = src;
	i = 0;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return ((void *)dest);
}
