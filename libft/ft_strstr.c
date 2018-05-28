/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgotta <frgotta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 15:49:12 by frgotta           #+#    #+#             */
/*   Updated: 2017/11/09 11:39:31 by frgotta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	if (*needle == '\0')
		return ((void *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (needle[j] && needle[j] == haystack[i + j])
			j++;
		if (needle[j] == '\0')
			return ((void *)(haystack + i));
		i++;
	}
	return (NULL);
}
