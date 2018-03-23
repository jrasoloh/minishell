/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 10:34:53 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/23 10:45:24 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		run_fork(char *path, char **cmd, char **env)
{
	pid_t		pid;

	if ((pid = fork()) == -1)
		ft_putendl("Error fork");
	if (pid > 0)
		wait(&pid);
	else if (pid == 0)
		execve(path, cmd, env);
}

void			run_execve(char **env, char **cmd)
{
	char		*path;
	char		**path_tab;

	if (check_elt_in_env(env, "PATH") == 1)
	{
		path = NULL;
		path_tab = get_path_tab(env, "PATH");
		if ((path = get_exe_path(cmd[0], path_tab)) != NULL)
		{
			run_fork(path, cmd, env);
			free(path);
		}
		else
			ft_putendl("Command not found");
		free_word_tab(path_tab);
	}
	else if (access(cmd[0], F_OK) != -1)
	{
		if (access(cmd[0], X_OK) != -1)
			run_fork(cmd[0], cmd, env);
		else
			ft_putendl("Permission denied");
	}
	else
		ft_putendl("Command not found");
}

char			**get_path_tab(char **env, char *path)
{
	char		*tmp;
	char		**tmp2;

	tmp = NULL;
	tmp2 = NULL;
	if (env == NULL || *env == NULL)
		return (NULL);
	if ((tmp = get_env(env, path)) != NULL)
		tmp2 = ft_strsplit(tmp, ':');
	return (tmp2);
}

char			*get_exe_path(char *path, char **path_tab)
{
	char		*tmp;
	char		*tmp2;
	int			i;

	tmp = NULL;
	tmp2 = NULL;
	i = 0;
	if (path_tab == NULL)
		return (NULL);
	while (path_tab[i])
	{
		tmp = ft_strjoin(path_tab[i], "/");
		tmp2 = ft_strjoin(tmp, path);
		free(tmp);
		if (access(tmp2, F_OK) != -1)
		{
			if (access(tmp2, X_OK) != -1)
				return (tmp2);
			else
			{
				free(tmp2);
				return (NULL);
			}
		}
		free(tmp2);
		i++;
	}
	return (NULL);
}
