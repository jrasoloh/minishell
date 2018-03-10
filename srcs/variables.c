/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 20:21:41 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/03/10 21:27:21 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char				*ft_store(char *str, int n)
{
	static char		*tab[100] = {0};
	static int		i = -1;

	if (str && n == 1)
		tab[++i] = str;
	if (n == -1)
		while (i > -1)
		{
			free(tab[i]);
			i--;
		}
	return (str);
}

size_t				ft_stop_char(char *str)
{
	size_t			i;

	i = 1;
	while (str[i++])
		if (ft_char_ok_env(str[i]) == 0)
			return (i);
	return (i);
}

static void			ft_interpret_bis(char **cmd, char **env)
{
	char			*new;
	char			*tail;
	size_t			stop;

	new = NULL;
	tail = NULL;
	stop = 0;
	if (ft_strlen(*cmd) > 1 && (*cmd)[0] == '$')
	{
		if ((stop = ft_stop_char(ft_store(*cmd, 1))) == ft_strlen(*cmd))
		{
			new = ft_strsub(*cmd, 1, ft_strlen(*cmd) - 1);
			*cmd = ft_get_env(env, new);
		}
		else
		{
			new = ft_strsub(*cmd, 1, stop - 1);
			tail = ft_strsub(*cmd, stop, ft_strlen(*cmd) - 1);
			*cmd = ft_strjoin(ft_get_env(env, new), tail);
			free(tail);
		}
		free(new);
	}
	ft_store(NULL, -1);
}

void			ft_interpret(char ***cmd, char **env)
{
	int			i;
	size_t		stop;
	char		*new;
	char		*tail;

	new = NULL;
	tail = NULL;
	if (*cmd == NULL || **cmd == NULL || ft_get_env_size(*cmd) < 2)
		return ;
	i = 0;
	stop = 0;
	while ((*cmd)[i] != NULL)
	{
		ft_interpret_bis(&(*cmd)[i], env);
		i++;
	}
	ft_store(NULL, -1);
}
