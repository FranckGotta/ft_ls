/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgotta <frgotta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 17:18:57 by frgotta           #+#    #+#             */
/*   Updated: 2017/11/09 12:46:42 by frgotta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;

	if ((mem = (char *)malloc(sizeof(*mem) * size)) == NULL)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
