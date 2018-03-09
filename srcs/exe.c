/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:53:13 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/07 21:04:48 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			ft_execve(char **env, char **cmd)
{
	char		*path;
	pid_t		pid;

	path = NULL;
	if ((path = ft_exe_path(cmd[0], ft_path_tab(env, "PATH"))) != NULL)
	{
		if ((pid = fork()) == -1)
			ft_putendl("Error fork");
		if (pid > 0)
			wait(&pid);
		else if (pid == 0)
			execve(path, cmd, env);
	}
	else if (access(cmd[0], F_OK) != -1)
	{
		if (access(cmd[0], X_OK) != -1)
		{
			if ((pid = fork()) == -1)
				ft_putendl("Error fork");
			if (pid > 0)
				wait(&pid);
			else if (pid == 0)
				execve(cmd[0], cmd, env);
		}
		else
			ft_putendl("Permission denied");
	}
	else
		ft_putendl("Command not found");
}
