/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:42:44 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:42:47 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getenv(char *name, char **envp)
{
	int	i;
	int	j;

	if ((name == NULL) | (envp == NULL))
		return (NULL);
	i = 0;
	j = 0;
	while (envp[i])
	{
		if (!ft_strncmp(name, envp[i], ft_strlen(name)))
		{
			j = i + ft_strlen(name) + 1;
			return (&(envp[i][j]));
		}
		else
			i++;
	}
	return (NULL);
}
