/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:41:18 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/07 20:03:21 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char			**ft_path_tab(char **env, char *path)
{
	return(ft_strsplit(ft_get_env(env, "PATH"), ':'));
}

char			*ft_exe_path(char *path, char **path_tab)
{
	char		*tmp;
	char		*res;
	int			i;

	tmp = NULL;
	res = NULL;
	i = 0;
	while (path_tab[i])
	{
		tmp = ft_strjoin(path_tab[i], "/");
		if (access(ft_strjoin(tmp, path), F_OK) != -1)
		{
			res = ft_strjoin(tmp, path);
			if (access(res, X_OK) != -1)
			{
//				free(tmp);
				return (res);
			}
			else
			{
				free(res);
				free(tmp);
				return (NULL);
		//		ft_putendl("Permission denied");
			}
		}
		i++;
	}
//	ft_putendl("Command not found");
	free(tmp);
	return (NULL);
}
