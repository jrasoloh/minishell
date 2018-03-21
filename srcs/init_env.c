/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:27:08 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/21 18:01:11 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char			**init_new_env(void)
{
	char		**t_env;

	t_env = (char **)malloc(sizeof(char *) * (2));
	t_env[0] = ft_strdup("SHVL=2");
	t_env[1] = NULL;
	return (t_env);
}

char			**copy_env(char **env)
{
	int			i;
	char		**res;
	int			len;

	len = get_env_size(env);
	res = NULL;
	i = 0;
	if ((res = (char **)malloc(sizeof(char *) * (len + 1))) != NULL)
	{
		while (i < len)
		{
			res[i] = ft_strdup(env[i]);
			i++;
		}
		res[i] = NULL;
	}
	return (res);
}

static char		*add_up_shlvl(char *shlvl)
{
	int			value;

	value = ft_atoi(shlvl) + 1;
	return (ft_itoa(value));
}

char			**add_shlvl(char **env)
{
	char		*res;
	char		*value;
	char		**new;

	res = NULL;
	new = NULL;
	if ((value = get_env(env, "SHLVL")) != NULL)
	{
		res = add_up_shlvl(value);
		new = set_env(&env, "SHLVL", res);
		free(res);
	}
	else
		new = set_env(&env, "SHLVL", "2");
	return (new);
}

char		**init_main_env(char **env, int ac, char **av)
{
	char	**t_env;

	(void)ac;
	(void)av;
	t_env = NULL;
	if (env == NULL || *env == NULL)
		t_env = init_new_env();
	else
	{
		t_env = copy_env(env);
		t_env = add_shlvl(t_env);
	}
	return (t_env);
}
