/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgotta <frgotta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 22:19:55 by frgotta           #+#    #+#             */
/*   Updated: 2017/11/24 22:02:10 by frgotta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t		i;
	char		*s1;
	char		*s2;
	size_t		n;

	if (*str2 == '\0')
		return ((void *)str1);
	n = ft_strlen(str2);
	i = 0;
	s1 = (void *)str1;
	s2 = (void *)str2;
	while (s1[i] && (i + n) <= len)
	{
		if (ft_memcmp(str1 + i, str2, n) == 0)
			return (s1 + i);
		i++;
	}
	return (NULL);
}
