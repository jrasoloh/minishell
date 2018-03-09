/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:03:31 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/09 17:58:46 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			ft_chdir_env(char ***env, char *path, char *oldpwd)
{
	*env = ft_setenv(*env, "OLDPWD", oldpwd);	
	*env = ft_setenv(*env, "PWD", path);
}

char			*ft_parent(char *str)
{
	int			i;
	int			end;
	char		*res;

	i = 0;
	end = ft_strlen(str) - 1;
	if (str[end] == '/')
		end--;
	while (str[end] != '/')
		end--;
	res = (char *)malloc(sizeof(char) * (end + 1));
	res[end] = '\0';
	while (i < end)
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}

void			ft_chdir_three(char ***env, char **cmd)
{
	char		*path;

	path = NULL;
	path = ft_strjoin(getcwd(NULL, 0), "/");
	path = ft_strjoin(ft_store(path, 1), cmd[1]);
	if (chdir(path) == -1)
		ft_error_chdir(cmd[1]);
}

void			ft_chdir_bis(char ***env, char **cmd)
{
	char		*tmp;
	char		*oldpwd;

	tmp = NULL;
	oldpwd = NULL;
	oldpwd = getcwd(NULL, 0);
	if (cmd[1][0] == '/')
	{
		if (chdir(cmd[1]) == -1)
			ft_putendl("Access denied");
		else
			ft_chdir_env(env, cmd[1], oldpwd);
	}
	else if (cmd[1][0] == '-')
	{
		if (ft_get_env(*env, "OLDPWD") != NULL)
		{
			if ((chdir(ft_get_env(*env, "OLDPWD"))) != -1)
				ft_chdir_env(env, ft_get_env(*env, "OLDPWD"), oldpwd);
			else
			{
				ft_putstr(ft_get_env(*env, "OLDPWD"));
				ft_putendl(": Access denied");
			}
		}
	}
	else if (cmd[1][0] == '.' && cmd[1][1] == '.')
	{
		chdir(ft_parent(oldpwd));
		ft_chdir_env(env, ft_parent(oldpwd), oldpwd);
	}
	else if (cmd[1][0] == '.' && cmd[1][1] != '.')
		return ;
	else if (ft_get_env(*env, "CDPATH") != NULL)
	{
		tmp = ft_store(ft_strjoin(ft_get_env(*env, "CDPATH"), "/"), 1);
		tmp = ft_strjoin(tmp, cmd[1]);
		if (chdir(tmp) != -1)
			ft_chdir_env(env, tmp, oldpwd);
	}
	else
		ft_chdir_three(env, cmd);
	ft_store(NULL, -1);
}

void			ft_chdir(char ***env, char **cmd)
{
	char		*tmp;
	char		*oldpwd;

	tmp = NULL;
	oldpwd = NULL;
	oldpwd = getcwd(NULL, 0);
	if (ft_get_env_size(cmd) > 2)
		ft_error_cd();
	else if (ft_get_env_size(cmd) == 1)
	{
		if ((tmp = ft_get_env(*env, "HOME")) != NULL)
		{
			chdir(tmp);
			*env = ft_setenv(*env, "OLDPWD", oldpwd); 
			*env = ft_setenv(*env, "PWD", tmp); 
		}
		else
			ft_putendl("HOME path is not defined");
	}
	else
		ft_chdir_bis(env, cmd);
	free(tmp);
}
