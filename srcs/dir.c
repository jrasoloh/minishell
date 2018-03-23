/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:32:13 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/23 19:15:47 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			ch_dir_env(char ***env, char *new_pwd, char *oldpwd)
{
	*env = set_env(env, "OLDPWD", oldpwd);
	*env = set_env(env, "PWD", new_pwd);
}

void			ch_dir(char ***env, char **cmd)
{
	char		*tmp;
	char		*oldpwd;

	tmp = NULL;
	oldpwd = NULL;
	if (get_env_size(cmd) > 2)
		error_cd();
	else if (get_env_size(cmd) == 1 || (get_env_size(cmd) == 2
				&& cmd[1][0] == '~' && ft_strlen(cmd[1]) == 1))
	{
		if ((tmp = get_env(*env, "HOME")) != NULL)
		{
			oldpwd = getcwd(NULL, 0);
			chdir(tmp);
			ch_dir_env(env, tmp, oldpwd);
			free(oldpwd);
		}
		else
			ft_putendl("HOME path is not defined");
	}
	else
		ch_dir_part_two(env, cmd);
}
