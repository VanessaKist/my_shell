/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:38:04 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:38:06 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_env(char *key, char *value)
{
	char	*name;

	name = ft_strjoin(key, value);
	append_to_envp(name, -1);
	free(name);
}

static int	error_handler_cd(char *str1, char *str2)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	return (1);
}

void	change_pwd_oldpwd(char **envp)
{
	char	*pwd;
	char	*oldpwd;
	char	*cwd;

	pwd = read_env(envp, "PWD");
	oldpwd = read_env(envp, "OLDPWD");
	if (pwd && *pwd && oldpwd)
		update_env("OLDPWD=", pwd);
	if (pwd && *pwd)
	{
		cwd = getcwd(NULL, 0);
		update_env("PWD=", cwd);
	}
	strclear(&cwd);
}

int	cd(char **envp, char **folder)
{
	char	*path;

	if (ft_matrix_size(folder) > 2)
		return (error_handler_cd("cd:", " too many arguments\n"));
	if (folder[1] && !(ft_strncmp(folder[1], "~", 2) == 0))
		path = folder[1];
	else
		path = read_env(envp, "HOME");
	if (chdir(path) != 0)
	{
		perror_handler(folder[1], ": ", 1, NULL);
		return (1);
	}
	change_pwd_oldpwd(envp);
	return (0);
}
