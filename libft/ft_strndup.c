/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:54:04 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:54:07 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*ptr;

	if (!n)
		return (NULL);
	ptr = ft_calloc((n + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	return (ft_memcpy(ptr, s, n));
}
