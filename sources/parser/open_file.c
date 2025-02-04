/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:32:07 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:32:11 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

void	open_input_file(t_cmd	*cmds, char *file)
{
	if (cmds->fd_in != 0)
		close(cmds->fd_in);
	cmds->fd_in = open(file, O_RDONLY);
	if (cmds->fd_in == -1)
	{
		g_data.exit_status = 1;
		g_data.error_flag = 1;
		perror_handler(file, ": ", 1, cmds);
		(cmds->flag_quit)++;
	}
}

void	open_output_file(t_cmd	*cmds, char *file)
{
	if (cmds->fd_out != 1)
		close(cmds->fd_out);
	cmds->fd_out = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cmds->fd_out == -1)
	{
		g_data.exit_status = 1;
		g_data.error_flag = 1;
		perror_handler(file, ": ", 1, cmds);
		(cmds->flag_quit)++;
	}
}

void	open_append_file(t_cmd	*cmds, char *file)
{
	if (cmds->fd_out != 1)
		close(cmds->fd_out);
	cmds->fd_out = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (cmds->fd_out == -1)
	{
		g_data.exit_status = 1;
		g_data.error_flag = 1;
		perror_handler(file, ": ", 1, cmds);
		(cmds->flag_quit)++;
	}
}
