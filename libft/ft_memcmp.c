/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:49:28 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:49:31 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (unsigned char *)b1;
	p2 = (unsigned char *)b2;
	if (len != 0)
	{	
		while (len--)
		{
			if (*p1 == *p2)
			{
				p1++;
				p2++;
			}
			else
				return (*p1 - *p2);
		}
	}
	return (0);
}
