/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:41:17 by vkist-si          #+#    #+#             */
/*   Updated: 2023/01/20 22:00:08 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

int heredoc(t_cmd *cmds, char *delimiter)
{
	char *line;
	
	line = readline("> ");
	while (line && !cmp(line, delimiter))
	{
		ft_putstr_fd(line, cmds->fd_in);
		free(line);
		line = readline("> ");
	}
	free(line);
	close(cmds->fd_in);
	return (open(HEREDOC, O_RDONLY));
}
