/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:47:28 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:47:31 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*last_node;

	if (lst && new_node)
	{
		if (*lst)
		{
			last_node = ft_lstlast(*lst);
			last_node->next = new_node;
		}
		else
			*lst = new_node;
	}
}
