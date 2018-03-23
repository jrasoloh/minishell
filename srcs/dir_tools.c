/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:46:03 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/23 10:28:33 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		ch_dir_part_six(char ***env, char **cmd)
{
	char		*oldpwd;
	char		*valid_path;

	oldpwd = NULL;
	valid_path = NULL;
	oldpwd = getcwd(NULL, 0);
	valid_path = join_n_shorten(oldpwd, cmd[1]);
	if (chdir(valid_path) == -1)
		error_chdir(cmd[1]);
	else
		ch_dir_env(env, valid_path, oldpwd);
	free(valid_path);
	free(oldpwd);
}

static void		ch_dir_part_five(char ***env, char **cmd)
{
	char		*oldpwd;
	char		*cdpath;
	char		*valid_path;

	oldpwd = NULL;
	valid_path = NULL;
	cdpath = NULL;
	if ((cdpath = get_env(*env, "CDPATH")) != NULL)
	{
		valid_path = join_n_shorten(cdpath, cmd[1]);
		oldpwd = getcwd(NULL, 0);
		if (chdir(valid_path) != -1)
			ch_dir_env(env, valid_path, oldpwd);
		free(valid_path);
		free(oldpwd);
	}
	else
		ch_dir_part_six(env, cmd);
}

static void		ch_dir_part_four(char ***env, char **cmd)
{
	char		*tmp;
	char		*oldpwd;
	char		*parent;

	tmp = NULL;
	oldpwd = NULL;
	parent = NULL;
	if (!(ft_strcmp(cmd[1], "..")) && ft_strlen(cmd[1]) == 2)
	{
		oldpwd = getcwd(NULL, 0);
		parent = get_parent(oldpwd);
		if (chdir(parent) != -1)
			ch_dir_env(env, parent, oldpwd);
		else
		{
			ft_putendl("cd: Unable to perform action");
		}
		free(oldpwd);
		free(parent);
	}
	else if (cmd[1][0] == '.' && ft_strlen(cmd[1]) == 1)
		return ;
	else
		ch_dir_part_five(env, cmd);
}

static void		ch_dir_part_three(char ***env, char **cmd)
{
	char		*oldpwd;
	char		*valid_path;
	char		*tmp;

	valid_path = NULL;
	oldpwd = NULL;
	tmp = NULL;
	if (cmd[1][0] == '/')
	{
		oldpwd = getcwd(NULL, 0);
		tmp = add_slash(ft_strdup(cmd[1]));
		valid_path = shorten_path(tmp);
		free(tmp);
		if (chdir(valid_path) == -1)
			ft_putendl("Access denied");
		else
			ch_dir_env(env, valid_path, oldpwd);
		free(valid_path);
		free(oldpwd);
	}
	else
		ch_dir_part_four(env, cmd);
}

void			ch_dir_part_two(char ***env, char **cmd)
{
	char		*oldpwd;
	char		*env_oldpwd;

	oldpwd = NULL;
	env_oldpwd = NULL;
	if (cmd[1][0] == '-' && ft_strlen(cmd[1]) == 1)
	{
		if ((env_oldpwd = ft_strdup(get_env(*env, "OLDPWD"))) != NULL)
		{
			oldpwd = getcwd(NULL, 0);
			if ((chdir(env_oldpwd)) != -1)
				ch_dir_env(env, env_oldpwd, oldpwd);
			else
				ft_putendl("cd: Access denied");
			free(oldpwd);
			free(env_oldpwd);
		}
		else
			ft_putendl("OLDPWD value is not defined");
	}
	else
		ch_dir_part_three(env, cmd);
}
