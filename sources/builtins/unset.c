/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:02:03 by etachott          #+#    #+#             */
/*   Updated: 2023/02/03 02:46:31 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

static int	is_valid(char *name)
{
	if (ft_strnstr(name, "=", ft_strlen(name))
		|| ft_strnstr(name, "-", ft_strlen(name)))
	{
		printf("minishell: unset: `%s': not a valid identifier\n", name);
		return (0);
	}
	return (1);
}

static void	remove_from_envp(char *name)
{
	char	**temp;
	char	*tmp_str;
	int		size;
	int		index;

	tmp_str = ft_strjoin(name, "=");
	index = 0;
	size = ft_matrix_size(g_data.envp);
	temp = ft_calloc(sizeof(char *), size);
	temp[size - 1] = NULL;
	size = 0;
	while (size < ft_matrix_size(g_data.envp) - 1)
	{
		if (ft_strncmp(g_data.envp[index], tmp_str, ft_strlen(tmp_str)) == 0)
			index++;
		else
		{
			temp[size] = ft_strdup(g_data.envp[index]);
			size++;
			index++;
		}
	}
	strsclear(g_data.envp);
	g_data.envp = temp;
	free(tmp_str);
}

int	builtin_unset(char **argv)
{
	int	index;

	index = 0;
	if (!argv[1])
		return (1);
	while (argv[++index])
	{
		if (is_valid(argv[index]))
			remove_from_envp(argv[index]);
		else
			return (1);
	}
	return (0);
}
