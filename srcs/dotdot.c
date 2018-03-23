/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dotdot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:22:28 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/23 10:29:02 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char				*skip_dotdot(char *str, size_t *i)
{
	char				*head;
	char				*parent;
	char				*res;

	head = NULL;
	parent = NULL;
	res = NULL;
	if (no_parent(str) == 1)
	{
		*i = 0;
		return ("/");
	}
	head = ft_strsub(str, 0, *i - 2);
	parent = get_parent(head);
	res = ft_strjoin(parent, &str[*i + 3]);
	*i = ft_strlen(parent);
	if (head)
		free(head);
	if (parent)
		free(parent);
	free(str);
	return (res);
}

static char				*rid_of_dotdot(char *path)
{
	static size_t		i;
	char				*pp;

	if (ft_strlen(path) > 2 && no_parent(path) == 1)
		return ("/");
	pp = ft_strdup(path);
	i = 3;
	while (i < ft_strlen(pp) && ft_strlen(pp) > 3 && !(no_parent(pp)))
	{
		if (pp[i] == '.' && pp[i - 1] == '/'
			&& pp[i + 1] == '.' && pp[i + 2] == '/')
		{
			pp = skip_dotdot(pp, &i);
			if (ft_strlen(pp) > 2 && no_parent(pp) == 1)
			{
				free(pp);
				return ("/");
			}
		}
		else
			i++;
	}
	return (pp);
}

static char				*skip_a_dot(char *str, int i)
{
	char				*head;
	char				*tail;
	char				*res;

	head = NULL;
	tail = NULL;
	head = ft_strsub(str, 0, i - 1);
	tail = &str[i + 1];
	res = ft_strjoin(head, tail);
	free(head);
	free(str);
	return (res);
}

static char				*rid_of_dot(char *path)
{
	int					i;
	char				*ppath;

	ppath = ft_strdup(path);
	i = ft_strlen(ppath) - 1;
	while (i > 0 && ft_strlen(ppath) > 2)
	{
		if (ppath[i] == '.' && ppath[i - 1] == '/' && ppath[i + 1] == '/')
		{
			ppath = skip_a_dot(ppath, i);
			i = ft_strlen(ppath) - 1;
		}
		else
			i = i - 1;
	}
	return (ppath);
}

char					*shorten_path(char *path)
{
	char				*tmp;
	char				*res;

	tmp = NULL;
	res = NULL;
	tmp = rid_of_dot(path);
	res = rid_of_dotdot(tmp);
	free(tmp);
	return (res);
}
