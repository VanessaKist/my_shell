/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:26:47 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:26:50 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

int	heredoc(t_cmd *cmds, char *delimiter)
{
	struct sigaction	s_sigint;
	struct sigaction	s_sigquit;
	char				*line;

	line = readline("> ");
	while (line && !cmp(line, delimiter))
	{
		set_signals(&s_sigint, &s_sigquit);
		ft_putendl_fd(line, cmds->fd_in);
		free(line);
		line = readline("> ");
	}
	free(line);
	close(cmds->fd_in);
	return (open(HEREDOC, O_RDONLY));
}
