/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:34:53 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/10 20:52:28 by jrasoloh         ###   ########.fr       */
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
