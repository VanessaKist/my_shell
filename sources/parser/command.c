/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:29:16 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:29:19 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

int	count_cmds(t_token *tokens)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while (tokens[i].name)
	{
		if (cmp(tokens[i].name, "|"))
			count++;
		i++;
	}
	return (count);
}

void	safe_init(t_cmd *cmds, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		cmds[i].cmd = NULL;
		cmds[i].cmds = NULL;
		cmds[i].fd_in = 0;
		cmds[i].fd_out = 1;
		cmds[i].path_cmd = NULL;
		cmds[i].pid = -1;
		cmds[i].where_read = STD_IN;
		cmds[i].where_write = STD_OUT;
		cmds[i].is_heredoc = 0;
		memset(cmds[i].pipe, 0, 2 * sizeof(int));
		i++;
	}
}

void	*fail_free_cmds(t_cmd *cmds)
{
	free_cmds(cmds);
	return (NULL);
}

t_cmd	*init_cmd_table(t_token *tokens)
{
	t_cmd	*cmds;
	int		i;
	int		j;

	i = -1;
	j = 0;
	cmds = ft_calloc(count_cmds(tokens) + 1, sizeof (t_cmd));
	safe_init(cmds, count_cmds(tokens) + 1);
	while (tokens[++i].name)
	{
		if (cmp(tokens[i].name, "<"))
			init_less_than(cmds, tokens, &i, &j);
		else if (cmp(tokens[i].name, "<<"))
			init_heredoc(cmds, tokens, &i, &j);
		else if (cmp(tokens[i].name, ">") || cmp(tokens[i].name, ">>"))
			init_greater_than(cmds, tokens, &i, &j);
		else if (cmp(tokens[i].name, "|"))
			init_pipe(cmds, &j);
		else
			init_normal(cmds, tokens, &i, &j);
	}
	return (cmds);
}
