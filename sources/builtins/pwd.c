/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:34:18 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:34:25 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(void)
{
	char	*str;

	str = NULL;
	str = getcwd(str, 4096);
	ft_putendl_fd(str, 1);
	strclear(&str);
	return (0);
}
