/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgotta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:12:21 by frgotta           #+#    #+#             */
/*   Updated: 2017/11/08 18:12:32 by frgotta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	tmp;

	tmp = c;
	len = ft_strlen(s);
	while (len > 0 && s[len] != tmp)
		len--;
	if (s[len] == tmp)
		return ((char *)&s[len]);
	return (NULL);
}
