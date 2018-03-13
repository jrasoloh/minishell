/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:01:23 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/13 12:43:04 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				ft_char_ok_env(char c)
{
	if ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	if (c == 45 || c == 95)
		return (1);
	return (0);
}

int				ft_name_ok_env(char *name)
{
	int			i;

	i = 0;
	while (name[i])
	{
		if (ft_char_ok_env(name[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

char			**ft_copy_env(char **env)
{
	int			i;
	char		**res;

	i = 0;
	while (env[i])
		i++;
	res = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		res[i] = ft_strdup(env[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

char			*ft_get_env(char **env, char *elt)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = ft_strjoin(elt, "=");
	while (env[i])
	{
		if ((ft_strcmp(tmp, ft_strsub(env[i], 0, ft_strlen(elt) + 1))) == 0)
		{
			return (ft_strsub(env[i], ft_strlen(elt) + 1, ft_strlen(env[i])));
		}
		i++;
	}
	free(tmp);
	return (NULL);
}

int				ft_check_elt_in_env(char **env, char *elt)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = ft_strjoin(elt, "=");
	while (env[i])
	{
		if (!(ft_strcmp(tmp, ft_strsub(env[i], 0, ft_strlen(elt) + 1))))
			return (1);
		i++;
	}
	free(tmp);
	return (0);
}
