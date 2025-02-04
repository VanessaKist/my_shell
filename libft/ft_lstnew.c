/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:48:39 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:48:42 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*set_key(char *cont)
{
	int		i;

	i = 0;
	while (cont[i])
	{
		if (cont[i] == '=')
			return (ft_substr(cont, 0, i));
		i++;
	}
	return (NULL);
}

char	*set_value(char *cont)
{
	int		i;

	i = 0;
	while (cont[i])
	{
		if (cont[i] == '=')
			return (ft_substr(cont, i + 1, (ft_strlen(cont) - (i + 1))));
		i++;
	}
	return (NULL);
}

t_list	*ft_lstenv_new(void *content)
{
	t_list	*lst;

	lst = ft_calloc(sizeof(t_list), 1);
	if (lst == NULL)
		return (NULL);
	lst->key = set_key(content);
	if (lst->key == NULL)
		return (NULL);
	lst->value = set_value(content);
	if (lst->value == NULL)
		return (NULL);
	lst->next = NULL;
	return (lst);
}
