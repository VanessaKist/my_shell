/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:31:38 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:31:41 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

void	fill_normal(char *line, int *i, t_token **tokens, int *curr_token)
{
	while (line[*i] && !ft_isspace(line[*i]) && !is_token(line[*i])
		&& !is_quote(line[*i]) && g_data.index < (*tokens)[*curr_token].size)
	{
		if (line[*i] && !ft_isspace(line[*i]) && !is_token(line[*i])
			&& g_data.index < (*tokens)[*curr_token].size)
		{
			(*tokens)[*curr_token].name[g_data.index] = line[*i];
			(*i)++;
			g_data.index++;
		}
	}
	if ((!line[*i]) || is_token(line[*i]) || ft_isspace(line[*i]))
	{
		(g_data.index) = 0;
		(*curr_token)++;
	}
}

t_token	*fill_tokens_content(char *line, t_token *tokens, int curr_token, int i)
{
	while (line[i])
	{
		if (ft_isspace(line[i]))
		{
			i++;
			continue ;
		}
		else if (line[i] == '"')
			fill_double(&i, line, &curr_token, &tokens);
		else if (line[i] == '\'')
			fill_single(&i, line, &curr_token, &tokens);
		else if (line[i] == '|')
			fill_pipe(&tokens, &curr_token, line, &i);
		else if (line[i] == '>')
			fill_greater(&tokens, &curr_token, &i, line);
		else if (line[i] == '<')
			fill_less(&tokens, &curr_token, &i, line);
		else
			fill_normal(line, &i, &tokens, &curr_token);
		if (!line[i])
			break ;
	}
	return (tokens);
}
