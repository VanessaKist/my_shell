/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:48:47 by tkomeno           #+#    #+#             */
/*   Updated: 2023/02/22 19:22:41 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

static int	check_return(char *str)
{
	if (ft_strlen(str) > 20)
		return (0);
	while (*str)
	{
		if ((*str < '0' || *str > '9')
			&& (*str != '\"' && *str != '-' && *str != '+'))
			return (0);
		str++;
	}
	return (1);
}

void	check_exit(char **args)
{
	int		exit_status;
	char	*str;

	exit_status = 0;
	str = args[1];
	if (args[2])
		exit_with_error("exit", "too many arguments", EXIT_FAILURE);
	else if (!check_return(str))
		exit_with_error("exit", "numeric argument required", 2);
	else
	{
		rl_clear_history();
		exit_status = ft_atoi_long(args[1]);
		break_free(&g_data);
		free_cmds(g_data.cmds);
		free_tokens(g_data.tokens);
		exit(exit_status);
	}
}

void	builtin_exit(char **args)
{
	write (1, "exit\n", 5);
	if (args[0] && !args[1])
	{
		free_cmds(g_data.cmds);
		free_tokens(g_data.tokens);
		break_free(&g_data);
		exit(0);
	}
	else
		check_exit(args);
}
