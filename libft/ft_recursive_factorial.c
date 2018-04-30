/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgotta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:38:33 by frgotta           #+#    #+#             */
/*   Updated: 2017/07/06 20:32:12 by frgotta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (nb >= 13)
		return (0);
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}
