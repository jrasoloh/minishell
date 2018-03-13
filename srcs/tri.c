/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:30:13 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/12 13:57:36 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char		*ft_dotdot(char **path)
{
	size_t		i;
	char		*pp;
	char		*hd;

	pp = *path;
	if (!(ft_strcmp("/..", ft_strsub(pp, 0, 2))))
		return ("/");
	hd = NULL;
	i = 1;
	while (i < ft_strlen(pp) && ft_strlen(pp) > 3)
	{
		if (pp[i] == '.' && pp[i - 1] == '/'
			&& pp[i + 1] == '.' && pp[i + 2] == '/')
		{
			ft_store(pp, 1);
			hd = ft_parent(ft_strsub(pp, 0, i - 2));
			pp = ft_strjoin(hd, ft_strsub(pp, i + 2, ft_strlen(pp) - 1));
			i = ft_strlen(hd);
		}
		else
			i++;
	}
	return (pp);
}

static char		*ft_dot(char **path)
{
	int			i;
	char		*ppath;
	char		*head;
	char		*tail;

	ppath = *path;
	head = NULL;
	tail = NULL;
	i = ft_strlen(ppath) - 1;
	while (i > 0 && ft_strlen(ppath) > 2)
	{
		if (ppath[i] == '.' && ppath[i - 1] == '/' && ppath[i + 1] == '/')
		{
			ft_store(ppath, 1);
			head = ft_store(ft_strsub(ppath, 0, i - 1), 1);
			tail = ft_store(ft_strsub(ppath, i + 1, ft_strlen(ppath) - 1), 1);
			ppath = ft_strjoin(head, tail);
			i = ft_strlen(ppath) - 1;
		}
		else
			i = i - 1;
	}
	ft_store(NULL, -1);
	return (ppath);
}

char			*ft_shorten_path(char *path)
{
	char		*tmp;

	tmp = NULL;
	if ((ft_strlen(path) == 1 && path[0] == '.')
		|| (ft_strlen(path) == 2 && !(ft_strcmp(path, "./"))))
		return (getcwd(NULL, 0));
	else if ((ft_strlen(path) == 2 && !(ft_strcmp(path, "..")))
			|| (ft_strlen(path) == 3 && !(ft_strcmp(path, "../"))))
		return (ft_parent(getcwd(NULL, 0)));
	else if (path[0] != '/')
	{
		tmp = ft_store(ft_strjoin(getcwd(NULL, 0), "/"), 1);
		tmp = ft_store(ft_strjoin(tmp, path), 1);
		ft_add_slash(&tmp);
		tmp = ft_dot(&tmp);
		ft_store(NULL, -1);
		return (ft_dotdot(&tmp));
	}
	else
	{
		tmp = ft_dot(&path);
		return (ft_dotdot(&tmp));
	}
}
