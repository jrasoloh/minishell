/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:34:53 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/12 12:35:42 by jrasoloh         ###   ########.fr       */
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
	int			end;

	if (ft_strlen(str) == 1 && str[0] == '/')
		return ("/");
	end = ft_strlen(str) - 1;
	if (str[end] == '/')
		end--;
	while (str[end] != '/')
		end--;
	return (ft_strsub(str, 0, end + 1));
}
