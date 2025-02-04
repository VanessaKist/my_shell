/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:30:13 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:30:17 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	count_as_token(char *line, int *i, int *tokens)
{
	(*tokens)++;
	while (line[*i] && !ft_isspace(line[*i]) && !is_token(line[*i]))
		(*i)++;
}

int	count_tokens(char *line)
{
	int	i;
	int	tokens;

	i = 0;
	tokens = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]))
			i++;
		else if (line[i] == '"')
			skip_double_quotes(line, &i, &tokens);
		else if (line[i] == '\'')
			skip_single_quotes(line, &i, &tokens);
		else if (line[i] == '|')
			skip_pipe(&i, &tokens);
		else if (line[i] == '>')
			skip_gt(&i, &tokens, line);
		else if (line[i] == '<')
			skip_lt(&i, &tokens, line);
		else
			count_as_token(line, &i, &tokens);
	}
	return (tokens);
}
