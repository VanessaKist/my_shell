/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:37:41 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:37:43 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

char	**set_env(char *envp[])
{
	int		index;
	char	**new_envp;

	index = 0;
	new_envp = NULL;
	while (envp[index])
		index++;
	new_envp = ft_calloc(sizeof(char *), index + 2);
	new_envp[index + 1] = NULL;
	new_envp[0] = ft_strdup("?=0");
	index = 1;
	while (envp[index])
	{
		new_envp[index] = ft_strdup(envp[index]);
		index++;
	}
	return (new_envp);
}

int	builtin_env(void)
{
	int	index;

	index = 1;
	while (g_data.envp[index])
	{
		ft_putendl_fd(g_data.envp[index], 1);
		index++;
	}
	return (0);
}

int	env_export_no_arg(void)
{
	int	index;

	index = 0;
	while (g_data.fenvp[++index])
	{
		printf("declare -x ");
		printf("%s\n", g_data.fenvp[index]);
	}
	return (0);
}
