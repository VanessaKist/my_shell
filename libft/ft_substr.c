/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:54:46 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:54:49 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	sub_len;

	i = 0;
	if (start > ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	sub_len = ft_strlen(&s[start]);
	if (len > sub_len)
		len = sub_len;
	sub = ft_calloc((len + 1), sizeof(char));
	if (! sub)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
