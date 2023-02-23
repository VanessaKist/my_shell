/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:16:29 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:16:32 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

void	sig_handler(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	set_signals(struct sigaction *s_sigint, struct sigaction *s_sigquit)
{
	s_sigint->sa_handler = &sig_handler;
	s_sigint->sa_flags = 0;
	sigemptyset(&s_sigint->sa_mask);
	sigaction(SIGINT, s_sigint, NULL);
	s_sigquit->sa_handler = SIG_IGN;
	s_sigquit->sa_flags = 0;
	sigemptyset(&s_sigquit->sa_mask);
	sigaction(SIGQUIT, s_sigquit, NULL);
}

void	set_execute_signals(int child_pid)
{
	struct sigaction	sa;

	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (child_pid == 0)
		sa.sa_handler = SIG_DFL;
	else
		sa.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}
