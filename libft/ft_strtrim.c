/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgotta <frgotta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 19:06:18 by frgotta           #+#    #+#             */
/*   Updated: 2017/11/09 15:08:22 by frgotta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_end_spaces(char const *str)
{
	size_t	i;
	size_t	count;

	i = ft_strlen(str) - 1;
	count = 0;
	while (i > 0 && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
	{
		i--;
		count++;
	}
	return (count);
}

static size_t		ft_begin_spaces(char const *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
	{
		i++;
		count++;
	}
	return (count);
}

char				*ft_strtrim(char const *s)
{
	size_t		begin;
	size_t		end;
	size_t		len;
	int			j;
	char		*str;

	if (!s)
		return (NULL);
	end = ft_end_spaces(s);
	begin = ft_begin_spaces(s);
	len = ft_strlen(s);
	j = 0;
	if (len - begin <= 0)
		return (ft_strdup(""));
	if ((str = (char *)malloc(sizeof(str) * (len - end - begin))) == NULL)
		return (NULL);
	while (s[begin] && begin < len - end)
	{
		str[j] = s[begin];
		begin++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
