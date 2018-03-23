/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 10:34:53 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/23 20:08:00 by jrasoloh         ###   ########.fr       */
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

static char		*slash_n_join(char *home, char *tail)
{
	char		*tmp;
	char		*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	if (home[ft_strlen(home) - 1] != '/')
		tmp = ft_strjoin(home, "/");
	else
		tmp = ft_strdup(home);
	tmp2 = ft_strjoin(tmp, tail);
	free(tmp);
	return (tmp2);
}

char			*get_exe_path(char *path, char **path_tab)
{
	char		*exe_path;
	int			i;

	exe_path = NULL;
	i = 0;
	if (path_tab == NULL)
		return (NULL);
	while (path_tab[i])
	{
		exe_path = slash_n_join(path_tab[i], path);
		if (access(exe_path, F_OK) != -1)
		{
			if (access(exe_path, X_OK) != -1)
				return (exe_path);
			else
			{
				free(exe_path);
				return (NULL);
			}
		}
		free(exe_path);
		i++;
	}
	return (NULL);
}
