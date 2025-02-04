/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:21:48 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:21:51 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

void	error_handler(char *cmd, char *error)
{
	write(1, "minishell: ", 11);
	ft_putstr_fd(cmd, 1);
	write(1, ": ", 2);
	ft_putstr_fd(error, 1);
	write(1, "\n", 1);
}

int	is_builtin_fork(char **prompt)
{
	if (ft_strncmp(prompt[0], "pwd", 4) == 0)
		return (1);
	if (ft_strncmp(prompt[0], "echo", 5) == 0)
		return (1);
	if (ft_strncmp(prompt[0], "env", 4) == 0)
		return (1);
	return (0);
}

int	is_builtin_unfork(char **prompt)
{
	if (ft_strncmp(prompt[0], "cd", 3) == 0)
		return (1);
	if (ft_strncmp(prompt[0], "exit", 5) == 0)
		return (1);
	if (ft_strncmp(prompt[0], "export", 7) == 0)
		return (1);
	if (ft_strncmp(prompt[0], "unset", 6) == 0)
		return (1);
	return (0);
}

int	builtin_run_fork(char **prompt)
{
	int	exitcode;

	exitcode = 0;
	if (ft_strncmp(prompt[0], "pwd", 4) == 0)
		exitcode = pwd();
	else if (ft_strncmp(prompt[0], "echo", 5) == 0)
		exitcode = echo(prompt);
	else if (ft_strncmp(prompt[0], "env", 4) == 0)
		exitcode = builtin_env();
	else
		return (1);
	return (exitcode);
}

int	builtin_run_unfork(char **prompt, char **envp)
{
	int	exitcode;

	exitcode = 1;
	if (ft_strncmp(prompt[0], "cd", 3) == 0)
		exitcode = cd(envp, prompt);
	else if (ft_strncmp(prompt[0], "exit", 5) == 0)
		builtin_exit(prompt);
	else if (ft_strncmp(prompt[0], "export", 7) == 0)
		exitcode = builtin_export(prompt);
	else if (ft_strncmp(prompt[0], "unset", 6) == 0)
		exitcode = builtin_unset(prompt);
	else
		return (1);
	g_data.exit_status = exitcode;
	return (exitcode);
}
