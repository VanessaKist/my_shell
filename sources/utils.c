/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:15:49 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:15:54 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	append_slash_to_path(char **paths)
{
	int		i;
	char	*tmp;

	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = tmp;
	}
}

int	count_iterations(t_cmd *cmds)
{
	int	i;

	i = 0;
	while (cmds[i].cmd)
		i++;
	return (i);
}

char	*fill_non_printable(void)
{
	char	*str;

	str = calloc(2, sizeof(char));
	str[0] = 32;
	return (str);
}

char	*fill_non_space(void)
{
	char	*str;

	str = calloc(2, sizeof(char));
	str[0] = 4;
	return (str);
}

int	count_rows(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}
