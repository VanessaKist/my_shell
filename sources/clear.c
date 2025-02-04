/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:28:29 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:28:33 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

void	strclear(char **str)
{
	if (!str)
		return ;
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

void	strsclear(char **ptrs)
{
	int	i;
	int	elements;

	if (!ptrs)
		return ;
	if (ptrs != NULL)
	{
		elements = count_rows(ptrs);
		i = 0;
		while (i < elements)
		{
			if (ptrs[i] != NULL)
				free(ptrs[i]);
			i++;
		}
		free(ptrs);
		ptrs = NULL;
	}
}

void	half_break_free(t_data	*data)
{
	data->flag_quit = 0;
	data->error_flag = 0;
	if (data->prompt)
		strsclear(data->prompt);
	if (data->str)
		strclear(&data->str);
	if (data->prompt_name)
		strclear(&data->prompt_name);
	close_fds();
}

void	break_free(t_data *data)
{
	if (data)
		half_break_free(data);
	if (data->envp)
		strsclear(data->envp);
	if (data->fenvp)
		strsclear(data->fenvp);
	rl_clear_history();
}

void	free_tokens(t_token *tokens)
{
	int	index;

	index = 0;
	while (tokens[index].name)
	{
		free(tokens[index].name);
		index++;
	}
	free(tokens);
}
