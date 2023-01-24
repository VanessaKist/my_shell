/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:29:35 by guribeir          #+#    #+#             */
/*   Updated: 2023/01/24 16:24:20 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	ft_envfree(t_list **env)
// {
// 	t_list	*prev_node;
// 	int		index;

// 	index = 0;
// 	prev_node = *env;
// 	if (!*env || !env)
// 		return ;
// 	while (*env && prev_node)
// 	{
// 		*env = (*env)->next;
// 		free(prev_node->key);
// 		free(prev_node->value);
// 		free(prev_node);
// 		prev_node = *env;
// 		index++;
// 	}
// 	*env = NULL;
// }

char	**change_env(char **envp, char *key, char *value)
{
	int		len;
	int		index;
	char	*tmp;
	char	*tmp2;

	len = ft_strlen(key);
	index = 0;
	tmp = ft_strjoin(key, "=");
	tmp2 = ft_strjoin(tmp, value);
	free(tmp);
	if (!key || !value)
		return (NULL);
	while (envp[index])
	{
		if (ft_strncmp(key, envp[index], len) == 0)
		{
			free(envp[index]);
			envp[index] = ft_strdup(tmp2);
			free(tmp2);
		}
		index++;
	}
	return (envp);
}

char	*read_env(char **envp, char *key)
{
	int		len;
	int		index;

	index = 0;
	len = ft_strlen(key);
	if (!key)
		return (NULL);
	while (envp[index])
	{
		if (ft_strncmp(key, envp[index], len) == 0)
			return (envp[index] + len + 1);
		index++;
	}
	return (NULL);
}

char	**change_exit_status(char **envp, int status)
{
	int		index;
	char	*str_status;
	char	**new_envp;

	index = 0;
	str_status = ft_itoa(status);
	new_envp = NULL;
	while (envp[index])
		index++;
	new_envp = ft_calloc(sizeof(char *), index + 2);
	new_envp[index + 1] = NULL;
	new_envp[0] = ft_strjoin("?=", str_status);
	index = 1;
	while (envp[index])
	{
		new_envp[index] = ft_strdup(envp[index]);
		index++;
	}
	strclear(&str_status);
	strsclear(envp);
	return (new_envp);
}
