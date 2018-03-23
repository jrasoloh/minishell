/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:26:27 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/23 20:09:47 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int					ft_strcmp_ref(char *ref, char *str)
{
	int				i;
	char			*tmp;

	i = -7;
	if (ref && str && (ft_strlen(str) >= ft_strlen(ref)))
	{
		tmp = ft_strsub(str, 0, ft_strlen(ref));
		i = ft_strcmp(ref, tmp);
		free(tmp);
	}
	return (i);
}

static int			char_ok_env_name(char c)
{
	if ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	if (c == 45 || c == 95)
		return (1);
	return (0);
}

int					name_ok_env(char *name)
{
	int				i;

	i = 0;
	while (name[i])
	{
		if (char_ok_env_name(name[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

size_t				stop_char(char *str)
{
	size_t			i;

	i = 1;
	while (str[i])
	{
		if (char_ok_env_name(str[i]) == 0)
			return (i);
		i++;
	}
	return (i);
}

char				*add_slash(char *str)
{
	char			*res;

	res = NULL;
	if (str[ft_strlen(str) - 1] != '/')
	{
		res = ft_strjoin(str, "/");
		free(str);
		return (res);
	}
	return (str);
}
