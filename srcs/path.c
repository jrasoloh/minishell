/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:41:18 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/10 21:17:48 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char			**ft_path_tab(char **env, char *path)
{
	return (ft_strsplit(ft_get_env(env, path), ':'));
}

char			*ft_exe_path(char *path, char **path_tab)
{
	char		*tmp;
	int			i;

	tmp = NULL;
	i = 0;
	while (path_tab[i])
	{
		tmp = ft_strjoin(path_tab[i], "/");
		if (access(ft_strjoin(tmp, path), F_OK) != -1)
		{
			if (access(ft_strjoin(tmp, path), X_OK) != -1)
			{
				free(tmp);
				return (ft_strjoin(tmp, path));
			}
			else
			{
				free(tmp);
				return (NULL);
			}
		}
		i++;
	}
	free(tmp);
	return (NULL);
}

void			ft_free_word_tab(char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}
