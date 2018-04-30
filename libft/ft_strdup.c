/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgotta <frgotta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 17:27:18 by frgotta           #+#    #+#             */
/*   Updated: 2017/11/09 11:25:23 by frgotta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*s_final;

	len = 0;
	while (s[len])
	{
		len++;
	}
	if ((s_final = (char *)malloc(sizeof(char) * len + 1)) == 0)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s_final[i] = s[i];
		i++;
	}
	s_final[i] = '\0';
	return (s_final);
}
