/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_inout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:17:50 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:17:55 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

void	select_inout(t_cmd *cmds, int i)
{
	if (cmds[i].where_read == FILE_IN)
	{
		if (dup2(cmds[i].fd_in, 0) == -1)
			perror_handler("dup: ", "", 1, cmds);
	}
	if (cmds[i].where_read == PIPE_0)
	{
		if (dup2(cmds[i - 1].pipe[0], 0) == -1)
			perror_handler("dup: ", "", 1, cmds);
	}
	if (cmds[i].where_write == PIPE_1)
	{
		if (dup2(cmds[i].pipe[1], 1) == -1)
			perror_handler("dup: ", "", 1, cmds);
	}
	if (cmds[i].where_write == FILE_OUT)
	{
		if (dup2(cmds[i].fd_out, 1) == -1)
			perror_handler("dup: ", "", 1, cmds);
	}
}

void	close_fds(void)
{
	close(g_data.std_in_fd);
	close(g_data.std_out_fd);
}
