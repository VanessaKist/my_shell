/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:37:51 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:37:55 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

static int	counter(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	put_str_increment(char **str, int *i)
{
	int	limit;

	limit = counter(str);
	ft_putstr_fd(str[*i], 1);
	if ((*i) < limit - 1)
		ft_putchar_fd(' ', 1);
	(*i)++;
}

int	echo(char **str)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (!str[1])
	{
		ft_putendl_fd("", 1);
		g_data.exit_status = 0;
		return (0);
	}
	if (ft_strncmp(str[i], "-n", 3) == 0)
	{
		i++;
		flag = -1;
	}
	while (str[i])
		put_str_increment(str, &i);
	if (flag == 0)
		ft_putchar_fd('\n', 1);
	g_data.exit_status = 0;
	return (0);
}
