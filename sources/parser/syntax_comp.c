/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_comp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:32:28 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:32:31 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_middle_syntax(t_token *tokens, int *i)
{
	if (tokens[*i + 1].is_sentinel)
		return (error_syntax("newline"));
	if (cmp(tokens[*i + 1].name, "|"))
		return (error_syntax("|"));
	else if (cmp(tokens[*i + 1].name, ">") || cmp(tokens[*i + 1].name, ">>")
		|| cmp(tokens[*i + 1].name, "<") || cmp(tokens[*i + 1].name, "<<"))
		return (error_syntax("newline"));
	return (0);
}

int	lesser_than_middle_syntax(t_token *tokens, int *i)
{
	if (tokens[*i + 1].is_sentinel)
		return (error_syntax("newline"));
	if (cmp(tokens[*i + 1].name, "<"))
		return (error_syntax("|"));
	else if (cmp(tokens[*i + 1].name, ">") || cmp(tokens[*i + 1].name, ">>")
		|| cmp(tokens[*i + 1].name, "|") || cmp(tokens[*i + 1].name, "<<"))
		return (error_syntax(tokens[*i + 1].name));
	return (0);
}

int	greater_than_middle_syntax(t_token *tokens, int *i)
{
	if (tokens[*i + 1].is_sentinel)
		return (error_syntax("newline"));
	if (cmp(tokens[*i + 1].name, ">"))
		return (error_syntax("|"));
	else if (cmp(tokens[*i + 1].name, "|") || cmp(tokens[*i + 1].name, ">>")
		|| cmp(tokens[*i + 1].name, "<") || cmp(tokens[*i + 1].name, "<<"))
		return (error_syntax(tokens[*i + 1].name));
	return (0);
}

int	append_syntax(t_token *tokens, int *i)
{
	if (tokens[*i + 1].is_sentinel)
		return (error_syntax("newline"));
	if (cmp(tokens[*i + 1].name, ">>"))
		return (error_syntax("|"));
	else if (cmp(tokens[*i + 1].name, ">") || cmp(tokens[*i + 1].name, "|")
		|| cmp(tokens[*i + 1].name, "<") || cmp(tokens[*i + 1].name, "<<"))
		return (error_syntax(tokens[*i + 1].name));
	return (0);
}

int	heredoc_syntax(t_token *tokens, int *i)
{
	if (tokens[*i + 1].is_sentinel)
		return (error_syntax("newline"));
	if (cmp(tokens[*i + 1].name, "<<"))
		return (error_syntax("|"));
	else if (cmp(tokens[*i + 1].name, ">") || cmp(tokens[*i + 1].name, ">>")
		|| cmp(tokens[*i + 1].name, "<") || cmp(tokens[*i + 1].name, "|"))
		return (error_syntax(tokens[*i + 1].name));
	return (0);
}
