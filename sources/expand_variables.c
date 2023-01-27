/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:09:50 by etachott          #+#    #+#             */
/*   Updated: 2023/01/26 22:32:48 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

static int	is_varname(char c)
{
	return (ft_isalnum(c) || c == '_' || c == '?');
}

static char	*find_var_position(char *input)
{
	while (*input)
	{
		if (*input == '\'')
		{
			input++;
			while (*input && *input != '\'')
				input++;
		}
		if (*input == '\"')
		{
			input++;
			while (*input && *input != '\"')
			{
				if (*input == '$' && is_varname(input[1]))
					return (input);
				input++;
			}
		}
		if (*input == '$' && is_varname(input[1]))
			return (input);
		input++;
	}
	return (NULL);
}

static void	update_input(char **input, char *var_value, char *second_part)
{
	char	*first_part;
	char	*updated_input;

	if (!*input[0] && !var_value)
		first_part = ft_strdup("");
	else if (!*input[0] && var_value)
		first_part = ft_strdup(var_value);
	else if (!var_value)
		first_part = ft_strdup(*input);
	else
		first_part = ft_strjoin(*input, var_value);
	updated_input = ft_strjoin(first_part, second_part);
	free(first_part);
	free(*input);
	*input = updated_input;
}

static char	*var_to_value(char *var_name)
{
	char	*key;
	int		key_size;
	int		index;

	key = ft_strjoin(var_name, "=");
	key_size = ft_strlen(key);
	index = 0;
	while (g_data.envp[index])
	{
		if (ft_strncmp(g_data.envp[index], key, key_size) == 0)
		{
			free(key);
			return (ft_strdup(g_data.envp[index] + key_size));
		}
		index++;
	}
	free(key);
	return (fill_non_printable());
}

void	expand_variables(char **input)
{
	char	*var_position;
	char	*var_name;
	char	*var_value;
	int		name_size;

	var_position = find_var_position(*input);
	if (var_position)
	{
		name_size = 0;
		while (is_varname(var_position[name_size + 1]))
			name_size++;
		var_name = ft_substr(var_position, 1, name_size);
		*var_position = '\0';
		var_value = var_to_value(var_name);
		update_input(input, var_value, (var_position + 1 + name_size));
		free(var_name);
		free(var_value);
		expand_variables(input);
	}
}
