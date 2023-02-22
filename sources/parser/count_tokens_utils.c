/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tokens_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:30:02 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:30:06 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_double_quotes(char *line, int *i, int *tokens)
{
	(*i)++;
	while (line[*i] && line[*i] != '"')
		(*i)++;
	if (line[*i] == '"')
		(*i)++;
	if ((!line[*i]) || is_token(line[*i]) || ft_isspace(line[*i]))
		(*tokens)++;
}

void	skip_single_quotes(char *line, int *i, int *tokens)
{
	(*i)++;
	while (line[*i] && line[*i] != '\'')
		(*i)++;
	if (line[*i] == '\'')
		(*i)++;
	if ((!line[*i]) || is_token(line[*i]) || ft_isspace(line[*i]))
		(*tokens)++;
}

void	skip_pipe(int *i, int *tokens)
{
	(*i)++;
	(*tokens)++;
}

void	skip_gt(int *i, int *tokens, char *line)
{
	(*i)++;
	if (line[*i] == '>')
		(*i)++;
	(*tokens)++;
}

void	skip_lt(int *i, int *tokens, char *line)
{
	(*i)++;
	if (line[*i] == '<')
		(*i)++;
	(*tokens)++;
}
