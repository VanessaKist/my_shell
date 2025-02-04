/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:32:17 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:32:20 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	before_double_quote(char *cmd)
{
	int	i;
	int	j;

	if (!cmd)
		return (0);
	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '\"' && cmd[i + 1] && cmd[i + 1] == ' ')
		{
			j = i + 1;
			while (cmd[j] && cmd[j] != '\"')
			{
				if (cmd[j] == ' ')
					cmd[j] = (char)(3);
				j++;
			}
			return (1);
		}
	}
	return (0);
}

static int	before_split(char *cmd)
{
	int	i;
	int	j;
	int	ret;

	ret = 0;
	if (!cmd)
		return (0);
	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '\'' && cmd[i + 1] && cmd[i + 1] == ' ')
		{
			j = i + 1;
			while (cmd[j] && cmd[j] != '\'')
			{
				if (cmd[j] == ' ')
					cmd[j] = (char)(3);
				j++;
			}
			return (1);
		}
	}
	ret = before_double_quote(cmd);
	return (ret);
}

static void	put_space(t_cmd *cmds)
{
	int		i;
	int		j;
	char	*aux;

	i = -1;
	while (cmds[++i].cmd)
	{
		j = -1;
		while (cmds[i].cmd[++j])
		{
			if (cmds[i].cmd[j] == (char)(3))
			{
				while (cmds[i].cmd[j] == (char)(3))
				{
					cmds[i].cmd[j] = ' ';
					j++;
				}
				aux = ft_strdup(cmds[i].cmd);
				free(cmds[i].cmd);
				cmds[i].cmd = ft_strtrim(aux, "\'\"");
				free(aux);
				return ;
			}
		}
	}
}

void	split_cmds(t_cmd *cmds)
{
	int		i;
	int		flag;

	if (!cmds)
		return ;
	i = 0;
	flag = 0;
	while (cmds[i].cmd)
	{
		flag = before_split(cmds[i].cmd);
		cmds[i].cmds = ft_split(cmds[i].cmd, 4);
		if (flag)
			put_space(cmds);
		if (!cmds[i].cmds)
			printf("Error malloc\n");
		i++;
	}
}
