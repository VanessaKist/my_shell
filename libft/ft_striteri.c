/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:52:36 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:52:39 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t			s_len;
	unsigned int	i;

	s_len = ft_strlen(s);
	i = 0;
	while (i < s_len && s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
