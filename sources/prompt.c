/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:19:46 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:19:51 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*set_prompt(const char *name)
{
	char	*line;

	line = readline(name);
	if (line == NULL)
		return (NULL);
	if (line && *line)
		add_history(line);
	return (line);
}
