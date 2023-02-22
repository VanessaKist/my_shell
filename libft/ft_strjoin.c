/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:52:45 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:52:47 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	if (!s2 || !s1)
		return (ft_strdup(s1));
	join = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (! join)
		return (NULL);
	ft_strlcpy(join, s1, ft_strlen(s1) + 1);
	ft_strlcat(join, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (join);
}
