/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:53:13 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/12 13:34:26 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		ft_fork(char *path, char **cmd, char **env)
{
	pid_t		pid;

	if ((pid = fork()) == -1)
		ft_putendl("Error fork");
	if (pid > 0)
		wait(&pid);
	else if (pid == 0)
		execve(path, cmd, env);
}

void			ft_execve(char **env, char **cmd)
{
	char		*path;

	if (ft_get_env(env, "PATH") != NULL)
	{
		path = NULL;
		if ((path = ft_exe_path(cmd[0], ft_path_tab(env, "PATH"))) != NULL)
		{
			ft_fork(path, cmd, env);
			free(path);
		}
	}
	else if (access(cmd[0], F_OK) != -1)
	{
		if (access(cmd[0], X_OK) != -1)
			ft_fork(cmd[0], cmd, env);
		else
			ft_putendl("Permission denied");
	}
	else
		ft_putendl("Command not found");
}

void			ft_add_slash(char **str)
{
	if ((*str)[ft_strlen(*str) - 1] != '/')
		ft_strjoin(*str, "/");
}
