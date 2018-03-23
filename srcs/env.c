/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:15:49 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/23 19:24:09 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char				*get_env(char **env, char *name)
{
	int				i;
	char			*label;
	int				len;

	i = 0;
	label = NULL;
	label = ft_strjoin(name, "=");
	len = ft_strlen(label);
	while (env[i])
	{
		if (ft_strcmp_ref(label, env[i]) == 0)
		{
			free(label);
			return (&env[i][len]);
		}
		i++;
	}
	free(label);
	return (NULL);
}

char				**set_env(char ***env, char *name, char *value)
{
	char			*label;
	char			*new_env;
	char			**res;

	if (name == NULL || value == NULL)
		return (*env);
	label = ft_strjoin(name, "=");
	new_env = ft_strjoin(label, value);
	free(label);
	res = NULL;
	if (env == NULL)
	{
		res = (char **)malloc(sizeof(char *) * (2));
		res[0] = new_env;
		res[1] = NULL;
	}
	else
	{
		if (check_elt_in_env(*env, name) == 1)
			res = switch_env_value(env, name, new_env);
		else
			res = add_to_env(*env, new_env);
	}
	return (res);
}

char				**unset_env(char **env, char *name)
{
	int				i;
	int				j;
	char			**res;
	char			*label;

	i = 0;
	j = 0;
	label = ft_strjoin(name, "=");
	res = (char **)malloc(sizeof(char *) * (get_env_size(env)));
	while (env[j] && i < get_env_size(env))
	{
		if (ft_strcmp_ref(label, env[j]))
		{
			res[i] = env[j];
			i++;
		}
		else
			free(env[j]);
		j++;
	}
	res[i] = NULL;
	free(label);
	free(env);
	return (res);
}

char				**add_to_env(char **env, char *new_env)
{
	int				i;
	char			**res;

	i = 0;
	res = NULL;
	res = (char **)malloc(sizeof(char *) * (get_env_size(env) + 2));
	while (env[i])
	{
		res[i] = env[i];
		i++;
	}
	res[i] = new_env;
	res[i + 1] = NULL;
	free(env);
	return (res);
}

char				**switch_env_value(char ***env, char *name, char *new_env)
{
	int				j;
	char			*name_env;
	char			*old_env;

	j = 0;
	old_env = NULL;
	name_env = ft_strjoin(name, "=");
	while ((*env)[j])
	{
		if (!ft_strcmp_ref(name_env, (*env)[j]))
		{
			old_env = (*env)[j];
			(*env)[j] = new_env;
			free(old_env);
		}
		j++;
	}
	free(name_env);
	return (*env);
}
