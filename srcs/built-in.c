/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:14:51 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/08 14:26:24 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void				ft_env(char **env)
{
	int				i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}

int					ft_get_env_size(char **env)
{
	int				i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char				**ft_unsetenv(char **env, char *name)
{
	int				i;
	int				j;
	char			**res;
	char			*tmp;

	i = 0;
	j = 0;
	tmp = ft_strjoin(name, "=");
	res = (char **)malloc(sizeof(char *) * (ft_get_env_size(env)));
	while (env[j] && i < ft_get_env_size(env))
	{
		if (ft_strcmp(tmp, ft_strsub(env[j], 0, ft_strlen(name) + 1)))
		{
			res[i] = env[j];
			i++;
		}
		else
			free(env[j]);
		j++;
	}
	free(tmp);
	res[i] = NULL;
	return (res);
}

char				**ft_copy_env_but_name(char **env, char *name, char *tmp)
{
	int				i;
	int				j;
	char			**res;
	char			*name_env;

	i = 0;
	j = 0;
	name_env = ft_strjoin(name, "=");
	res = (char **)malloc(sizeof(char *) * (ft_get_env_size(env) + 1));
	while (env[j] && i < ft_get_env_size(env))
	{
		if (ft_strcmp(name_env, ft_strsub(env[j], 0, ft_strlen(name) + 1)))
		{	
			res[i] = env[j];
			i++;
//			j++;
		}
//		else
			j++;
	}
	res[i] = tmp;
	i++;
	res[i] = NULL;
	return (res);
}

char				**ft_add_to_env(char **env, char *name, char *tmp)
{
	int				i;
	char			**res;

	i = 0;
	res = (char **)malloc(sizeof(char *) * (ft_get_env_size(env) + 2));
	while (env[i])
	{
		res[i] = env[i];
	//	res[i] = ft_strdup(env[i]);
		i++;
	}
//	res[i] = ft_strdup(tmp);
	res[i] = tmp;
	i++;
	res[i] = NULL;
	return (res);
}

char				**ft_setenv(char **env, char *name, char *value)
{
	char			*tmp;
	char			*tmp2;
	char			**res;

	if (name == NULL || value == NULL)
		return (env);
	tmp = ft_strjoin(name, "=");
	tmp2 = ft_strjoin(tmp, value);
	free(tmp);
	if (env == NULL)
	{
		res = (char **)malloc(sizeof(char *) * (2));
		res[0] = tmp2;
		res[1] = NULL;
	}
	else
	{
		if (ft_check_elt_in_env(env, name) == 1)
			res = ft_copy_env_but_name(env, name, tmp2);
		else
			res = ft_add_to_env(env, name, tmp2);
	}
	return (res);
}
