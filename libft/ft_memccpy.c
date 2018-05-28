/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgotta <frgotta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 20:17:56 by frgotta           #+#    #+#             */
/*   Updated: 2017/11/09 10:52:30 by frgotta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	char			*dest1;
	char			*src1;

	dest1 = (void *)dest;
	src1 = (void *)src;
	i = 0;
	while (i < n)
	{
		dest1[i] = src1[i];
		if (src1[i] == c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
