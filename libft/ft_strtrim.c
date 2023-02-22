/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:54:36 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:54:38 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end_sub;

	while (*s1 && ft_strchr(set,*s1))
	{
		s1++;
	}
	end_sub = ft_strlen(s1);
	while (end_sub && ft_strchr(set, s1[end_sub]))
	{
		end_sub--;
	}
	return (ft_substr(s1, 0, end_sub + 1));
}
