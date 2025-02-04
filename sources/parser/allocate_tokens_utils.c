/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_tokens_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:28:40 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:28:44 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

void	allocate_double(int *curr_token, int *curr_token_size, char *line,
		int *i)
{
	(*i)++;
	while (line[*i] && line[*i] != '"')
	{
		(*i)++;
		(*curr_token_size)++;
	}
	if (line[*i] == '"')
		(*i)++;
	if ((!line[*i]) || is_token(line[*i]) || ft_isspace(line[*i]))
		(*curr_token)++;
}

void	allocate_single(int *curr_token, int *curr_token_size, char *line,
		int *i)
{
	(*i)++;
	while (line[*i] && line[*i] != '\'')
	{
		(*i)++;
		(*curr_token_size)++;
	}
	if (line[*i] == '\'')
		(*i)++;
	if ((!line[*i]) || is_token(line[*i]) || ft_isspace(line[*i]))
		(*curr_token)++;
}

void	allocate_pipe(int *curr_token, int *curr_token_size, int *i)
{
	(*curr_token)++;
	(*curr_token_size)++;
	(*i)++;
	g_data.skip = 1;
}

void	allocate_greater(int *curr_token, int *curr_token_size, char *line,
		int *i)
{
	(*curr_token)++;
	(*curr_token_size)++;
	if (line[*i + 1] && line[*i + 1] == '>')
	{
		(*i)++;
		(*curr_token_size)++;
	}
	(*i)++;
	g_data.skip = 1;
}

void	allocate_less(int *curr_token, int *curr_token_size, char *line, int *i)
{
	(*curr_token)++;
	(*curr_token_size)++;
	if (line[*i + 1] && line[*i + 1] == '<')
	{
		(*i)++;
		(*curr_token_size)++;
	}
	(*i)++;
	g_data.skip = 1;
}
