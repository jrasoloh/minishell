/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:16:08 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/23 20:51:03 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				no_parent(char *path)
{
	if (ft_strlen(path) > 2
			&& path[0] == '/' && path[1] == '.' && path[2] == '.')
		return (1);
	return (0);
}

char			*get_parent(char *path)
{
	int			end;

	if (ft_strlen(path) == 1 && path[0] == '/')
		return (ft_strdup("/"));
	end = ft_strlen(path) - 1;
	if (path[end] == '/')
		end--;
	while (end >= 0 && path[end] != '/')
		end--;
	if (end <= 0)
		return (ft_strdup("/"));
	return (ft_strsub(path, 0, end + 1));
}

char			*join_n_shorten(char *home, char *tail)
{
	char		*tmp;
	char		*tmp2;
	char		*res;

	tmp = NULL;
	tmp2 = NULL;
	res = NULL;
	if (home[ft_strlen(home) - 1] != '/')
		tmp = ft_strjoin(home, "/");
	else
		tmp = ft_strdup(home);
	tmp2 = add_slash(ft_strjoin(tmp, tail));
	free(tmp);
	res = shorten_path(tmp2);
	free(tmp2);
	return (res);
}
