/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:37:57 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/23 19:16:11 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			print_env(char **env)
{
	int			i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}

void			free_word_tab(char **tab)
{
	int			i;

	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

int				get_env_size(char **env)
{
	int			i;

	i = 0;
	while (env[i] != NULL)
		i++;
	return (i);
}

int				check_elt_in_env(char **env, char *elt)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = ft_strjoin(elt, "=");
	while (env[i] != NULL)
	{
		if (!ft_strcmp_ref(tmp, env[i]))
		{
			free(tmp);
			return (1);
		}
		i++;
	}
	free(tmp);
	return (0);
}
