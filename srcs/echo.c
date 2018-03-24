/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:06:55 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/24 12:45:19 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void				echo(char **cmd)
{
	int				i;

	if (cmd == NULL || *cmd == NULL || get_env_size(cmd) < 2)
		ft_putchar('\n');
	else
	{
		i = 1;
		while (i < get_env_size(cmd) - 1)
		{
			ft_putstr(cmd[i]);
			ft_putchar(' ');
			i++;
		}
		if (cmd[i])
			ft_putstr(cmd[i]);
		ft_putchar('\n');
	}
}

static void			interpret_bis(char **cmd, char **env)
{
	char			*new;
	char			*old;
	size_t			stop;

	new = NULL;
	old = NULL;
	stop = 0;
	if (ft_strlen(*cmd) > 1 && (*cmd)[0] == '$' 
			&& (check_elt_in_env(env, *cmd) == 1))
	{
		if ((stop = stop_char(*cmd)) == ft_strlen(*cmd))
		{
			old = *cmd;
			*cmd = ft_strdup(get_env(env, &(*cmd)[1]));
			free(old);
		}
		else
		{
			new = ft_strsub(*cmd, 1, stop - 1);
			old = *cmd;
			*cmd = ft_strjoin(get_env(env, new), &(*cmd)[stop]);
			free(new);
			free(old);
		}
	}
}

static void			interpret_var(char ***cmd, char **env)
{
	int				i;

	if (*cmd == NULL || **cmd == NULL || get_env_size(*cmd) < 2)
		return ;
	i = 0;
	while ((*cmd)[i] != NULL)
	{
		interpret_bis(&(*cmd)[i], env);
		i++;
	}
}

char				**arrange_var(char *buf, char **env)
{
	char			**res;

	res = ft_split(buf);
	if (get_env_size(res) > 1)
		interpret_var(&res, env);
	return (res);
}
