/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgotta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:07:29 by frgotta           #+#    #+#             */
/*   Updated: 2017/11/21 12:11:28 by frgotta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_words(char const *s, char c)
{
	int	words;
	int i;

	i = 0;
	words = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			words++;
		i++;
	}
	if (s[0] != '\0')
		words++;
	return (words);
}

static	char	*ft_print_words(char const *s, char c, int *i)
{
	char	*str;
	int		k;

	if ((str = (char *)malloc(sizeof(*s) * ft_strlen(s))) == 0)
		return (NULL);
	k = 0;
	while (s[*i] != c && s[*i])
	{
		str[k] = s[*i];
		k++;
		*i += 1;
	}
	str[k] = '\0';
	while (s[*i] == c && s[*i])
		*i += 1;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		words;
	char	**blocks;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	if ((blocks = (char **)malloc(sizeof(blocks) * (words + 2))) == NULL)
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (j < words && s[i])
	{
		blocks[j] = ft_print_words(s, c, &i);
		j++;
	}
	blocks[j] = NULL;
	return (blocks);
}
