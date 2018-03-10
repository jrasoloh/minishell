/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 18:54:23 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/10 21:03:56 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			ft_env(char **env)
{
	int			i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}

void			ft_add_shlvl(char ***env)
{
	char		*res;
	char		*value;

	res = (char *)malloc(sizeof(char) * (2));
	res[1] = '\0';
	value = NULL;
	if ((value = ft_get_env(*env, "SHLVL")) != NULL)
	{
		res[0] = value[0] + 1;
		*env = ft_setenv(*env, "SHLVL", res);
	}
	else
		*env = ft_setenv(*env, "SHLVL", "2");
	free(value);
	free(res);
	ft_store(NULL, -1);
}

void			ft_prompt(char **env)
{
	if (env != NULL && *env != NULL && ft_get_env(env, "PWD") != NULL)
	{
		ft_putstr(getcwd(NULL, 0));
		ft_putstr("> ");
	}
	else
		ft_putstr("$> ");
}

void			ft_print_word_tab(char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}
